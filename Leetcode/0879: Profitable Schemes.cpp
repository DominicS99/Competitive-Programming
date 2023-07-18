class Solution {
public:
    int MOD = 1e9+7;
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int r = group.size();
        int memo[r][n+1][minProfit+1];
        memset(memo, -1, sizeof(memo));
        
        function <int (int, int, int)> solve = [&] (int l, int members, int sum) {
            if (members > n) return 0;
            if (l == r) return (sum >= minProfit ? 1 : 0);
            if (sum > minProfit) sum = minProfit;
            auto &res = memo[l][members][sum];
            if (res > -1) return res;

            return res = (solve(l+1, members, sum) + solve(l+1, members + group[l], sum + profit[l]))%MOD;
        };

        return solve(0, 0, 0);
    }
};
