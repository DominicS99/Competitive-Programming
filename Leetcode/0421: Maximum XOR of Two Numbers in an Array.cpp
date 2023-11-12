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
    int findMaximumXOR(vector<int>& nums) {
        xorTrie trie;
        int res = 0;
        for (auto &x : nums) trie.insert(x);
        for (auto &x : nums) res = max(res, trie.maxXor(x));
        return res;
    }
};