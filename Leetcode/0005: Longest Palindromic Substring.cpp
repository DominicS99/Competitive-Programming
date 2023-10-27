class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int memo[n][n];
        memset(memo, -1, sizeof(memo));

        int resLength = 1, a = 0;
        function<int(int, int)> solve = [&] (int i, int j) {
            if (i > j) return 1;
            auto &res = memo[i][j];
            if (res != -1) return res;
            if (i == j) return res = 1;

            if (s[i] == s[j] && solve(i+1, j-1)) {
                if (resLength < j-(i-1)) {
                    resLength = j-(i-1);
                    a = i;
                }
                return res = 1;
            }
            solve(i+1, j);
            solve(i, j-1);

            return res = 0;
        };

        solve(0, n-1);
        return s.substr(a, resLength);
    }
};