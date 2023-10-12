class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        for (int j = 0; j < strs[0].size(); j++) {
            char curr = strs[0][j];
            for (int i = 1; i < strs.size(); i++) {
                if (j >= strs[i].size() || curr != strs[i][j]) return res;
            }
            res += curr;
        }
        return res;
    }
};