class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int res = 0;
        map<char, int> m;
        for (int i = 0; i < 26; i++) {
            m[i+'a'] = i+1;
        }
        
        for (int i = 0; i < chars.length(); i++) {
            m[chars[i]] = vals[i];
        }
        
        int curr = 0;
        for (char c : s) {
            curr += m[c];
            curr = max(curr, 0);
            res = max(res, curr);
        }
        
        return res;
    }
};
