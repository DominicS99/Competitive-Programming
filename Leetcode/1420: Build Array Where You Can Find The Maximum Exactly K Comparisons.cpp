class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        int MOD = 1e9+7;
        int memo[n+1][m+1][k+1];
        memset(memo, -1, sizeof(memo));

        function<int(int, int, int)> solve = [&] (int i, int num, int lim) {
            auto &res = memo[i][num][lim];
            if (res != -1) return res;
            if (i == n && lim == k) return res = 1;
            if (i == n) return res = 0;

            res = 0;
            for (int j = 1; j <= num; j++) {
                res += solve(i+1, num, lim);
                res %= MOD;
            }
            if (lim == k) return res;

            for (int j = num+1; j <= m; j++) {
                res += solve(i+1, j, lim+1);
                res %= MOD;
            }
            return res;
        };

        return solve(0, 0, 0);
    }
};