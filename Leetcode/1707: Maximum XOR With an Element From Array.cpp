typedef pair<int, int> pii;
typedef pair<int, pii> p3i;

struct xorTrie {
   long long totBits = (long long)1<<30;
   xorTrie* children[2] = {NULL, NULL};
   xorTrie() {}
   void insert(int x) {
       xorTrie *node = this;
       for (long long b = totBits; b; b >>= 1) {
           long long curr = (x & b) > 0;
           if (!node->children[curr]) node->children[curr] = new xorTrie();
           node = node->children[curr];
       }
   }
   bool remove(int x, long long b) {
       if (!b) return true;
       long long curr = (x & b) > 0;
       if (children[curr] && children[curr]->remove(x, b >> 1)) {
           delete children[curr];
           children[curr] = NULL;
       }
       return children[0] == children[1];
   }
   bool remove(int x) {
       return remove(x, totBits);
   }
   int maxXor(int x) {
       int res = 0;
       xorTrie *node = this;
       for (long long b = totBits; b; b >>= 1) {
           long long curr = (x & b) > 0;
           if (node->children[!curr]) {
               res += b;
               node = node->children[!curr];
           } else {
               node = node->children[curr];
           }
       }
       return res;
   }
};


class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        xorTrie trie;
        int n = nums.size(), l = 0;
        sort(nums.begin(), nums.end());

        int q = queries.size();
        priority_queue<p3i, vector<p3i>, greater<p3i>> pq;
        for (int i = 0; i < q; i++) {
            pq.push({queries[i][1], {queries[i][0], i}});
        }

        bool f = false;
        vector<int> res(q, -1);
        while (!pq.empty()) {
            auto [lim, info] = pq.top(); pq.pop();
            auto &[x, idx] = info;

            while (l < n && nums[l] <= lim) {
                trie.insert(nums[l++]);
                f = true;
            }

            if (!f) continue;
            res[idx] = trie.maxXor(x);
        }
        return res;
    }
};