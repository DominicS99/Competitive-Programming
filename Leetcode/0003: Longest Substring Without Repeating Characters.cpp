class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int res = 0, curr = 0;
        map<char, int> m;
        for (int l = 0, r = 0; r < n; r++) {
            char c = s[r];
            if (m[c] == 1) {
                res = max(res, curr);
                while (s[l] != c) {
                    m[s[l++]]--;
                    curr--;
                }
                l++;
            } else {
                m[c]++;
                curr++;
            }
        }
        return max(res, curr);
    }
};