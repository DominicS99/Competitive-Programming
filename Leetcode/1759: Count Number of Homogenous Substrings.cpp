class Solution {
public:
    int countHomogenous(string s) {
        int MOD = 1e9+7;
        int n = s.length();
        int res = 0;
        char curr = '0';
        for (int l = -1, r = 0; r < n; r++) {
            if (curr != s[r]) {
                curr = s[r];
                l = r-1;
            }
            long long x = r-l;
            res = (res+x)%MOD;
        }
        return res;
    }
};