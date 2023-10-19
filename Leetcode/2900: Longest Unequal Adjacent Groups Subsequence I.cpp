class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<string> res;
        int curr = -1;
        for (int i = 0; i < n; i++) {
            if (groups[i] != curr) {
                curr = groups[i];
                res.push_back(words[i]);
            }
        }
        return res;
    }
};