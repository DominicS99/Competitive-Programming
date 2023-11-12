typedef pair<int, int> pii;

struct xorTrie {
    int amtUsed;
    long long totBits;
    xorTrie* children[2] = {NULL, NULL};

    xorTrie() {
       totBits = (long long)1<<18;
       amtUsed = 0;
    }
    void insert(int x) {
        xorTrie *node = this;
        for (long long b = totBits; b; b >>= 1) {
            long long curr = (x & b) > 0;
            node->amtUsed++;
            if (!node->children[curr]) node->children[curr] = new xorTrie();
            node = node->children[curr];
        }
        node->amtUsed++;
    }
    void remove(int x) {
        xorTrie *node = this;
        for(long long b = totBits; b; b >>= 1){
            long long curr = (x & b) > 0;
            node->amtUsed--;
            node = node->children[curr];
        }
        node->amtUsed--;
    }
    int maxXor(int x) {
        int res = 0;
        xorTrie *node = this;
        for (long long b = totBits; b; b >>= 1) {
            long long curr = (x & b) > 0;
            if (node->children[!curr] && node->children[!curr]->amtUsed) {
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
    vector<vector<pii>> m;
    vector<vector<int>> reversed;
    vector<int> res;

    void dfs(int u, xorTrie *trie) {
        trie->insert(u);
        for (auto &[idx, x] : m[u]) {
            res[idx] = trie->maxXor(x); 
        }

        for (auto &v : reversed[u]) {
            dfs(v, trie);
        }
        trie->remove(u);
    }

    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int n = parents.size(), root;
        reversed.resize(n);
        m.resize(n);
        for (int i = 0; i < n; i++) {
            if (parents[i] == -1) root = i;
            else reversed[parents[i]].push_back(i);
        }

        int k = queries.size();
        for (int i = 0; i < k; i++) {
            m[queries[i][0]].emplace_back(i, queries[i][1]);
        }

        xorTrie *trie = new xorTrie();
        res.resize(k);
        dfs(root, trie);
        return res;
    }
};