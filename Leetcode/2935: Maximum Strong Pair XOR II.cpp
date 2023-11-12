/*
* One of those things where you either know it or don't.
* Transformed boiler plate xorTrie into my own version, so hopefully I'll be able to use it later on.
* From what I understand, it's a number trie using bits instead of characters, with an extra function to find maxXor based on possible bit combos (numbers) inserted.
*/

struct xorTrie {
    long long totBits = (long long)1<<20;
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
    int maximumStrongPairXor(vector<int>& nums) {
        xorTrie trie;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int res = 0;
        for (int l = 0, r = 0; r < n; r++) {
            trie.insert(nums[r]);
            while (nums[l]*2 < nums[r]) trie.remove(nums[l++]);
            res = max(res, trie.maxXor(nums[r]));
        }
        return res;
    }
};