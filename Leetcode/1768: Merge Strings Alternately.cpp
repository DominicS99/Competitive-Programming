class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        int m = word1.length(), n = word2.length();
        int l = 0, r = 0;
        while (l < m || r < n) {
            if (l < m) res += word1[l++];
            if (r < n) res += word2[r++];
        }
        return res;
    }
};
