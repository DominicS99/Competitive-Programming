class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();

        int memo[m+1][n+1];
        memset(memo, -1, sizeof(memo));
        
        function<bool (int, int)> solve = [&] (int l, int r) {
            auto &res = memo[l][r];
            if (res > -1) return res;
            if (r == n) return res = (l == m);
            if (l == m) {
                if (r < n-1 && p[r+1] == '*') {
                    return res = solve(l, r+2);
                } else {
                    return res = 0;
                }
            }

            if (s[l] == p[r] || p[r] == '.') {
                if (r < n-1 && p[r+1] == '*') {
                    return res = solve(l+1, r) || solve(l, r+2);
                } else {
                    return res = solve(l+1, r+1);
                }
            } else {
                if (r < n-1 && p[r+1] == '*') {
                    return res = solve(l, r+2);
                }
            }

            return res = 0;
        };
        
        return solve(0, 0);
    }
};