class Solution {
public:
    int MOD = 1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> memo(target, vector<int>(n, -1));

        function<int (int, int)> solve = [&] (int sum, int l) {
            if (l == n) return (sum == target ? 1 : 0);
            if (sum >= target) return 0;
            auto &res = memo[sum][l];
            if (res > -1) return res;

            res = 0;
            for (int i = 1; i <= k; i++) {
                res += solve(sum+i, l+1);
                res %= MOD;
            }
            return res;
        };

        return solve(0, 0);
    }
};
