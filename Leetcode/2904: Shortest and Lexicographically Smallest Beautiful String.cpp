class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int ones = 0, len = 1e9;
        string res;
        int n = s.length();
        for (int l = 0, r = 0; r < n; r++) {
            if (s[r] == '1') ones++;

            if (ones == k) {
                while (l < r && s[l] == '0') l++;

                int currLen = r+1-l;

                string curr = s.substr(l, currLen);
                if (len > currLen) {
                    res = curr;
                    len = currLen;
                } else if (len == currLen) {
                    res = min(res, curr);
                }

                l++;
                ones--;
            }
        }

        return res;
    }
};