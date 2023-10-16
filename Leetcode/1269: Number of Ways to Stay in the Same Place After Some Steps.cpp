class Solution {
public:
    int numWays(int steps, int arrLen) {
        int MOD = 1e9+7;
        arrLen = min(steps/2 + 1, arrLen);
        int memo[arrLen+1][steps+1];
        memset(memo, -1, sizeof(memo));

        function<int(int, int)> solve = [&] (int i, int k) {
            auto &res = memo[i][k];
            if (res != -1) return res;
            if (k == 0) return res = (i == 0);

            res = solve(i, k-1);
            if (i > 0) res = (res + solve(i-1, k-1)) % MOD;
            if (i+1 < arrLen) res = (res + solve(i+1, k-1)) % MOD;
            return res;
        };

        return solve(0, steps);
    }
};