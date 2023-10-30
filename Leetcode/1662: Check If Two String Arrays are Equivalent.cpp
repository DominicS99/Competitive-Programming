class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int a = 0, b = 0, i = 0, j = 0;
        while (a < word1.size() && b < word2.size()) {
            if (word1[a][i] != word2[b][j]) return false;
            if (++i == word1[a].size()) a++, i = 0;
            if (++j == word2[b].size()) b++, j = 0;
        }
        return a == word1.size() && b == word2.size();
    }
};