class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int l = 0, res = 0, count = 0, curr = 0;
        while (l < s.length() && s[l] != '0') {
            l++;
        }
        for (int i = l; i < s.length(); i++) {
            if (s[i] == '0') {
                if (i == 0 || s[i-1] == '1') {
                    count = 0;
                    res = max(res, curr*2);
                    curr = 0;
                }
                count++;
            } else if (curr < count) {
                curr++;
            }
        }
        return max(res, curr*2);
    }
};
