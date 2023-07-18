class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> memo(n, vector<vector<int>>(2, vector<int>(3, -1)));
        function <int (int, bool, int)> solve = [&] (int l, bool b, int times) {
            if (l == n) return 0;
            if (times == 2) return 0;
            auto &res = memo[l][b][times];
            if (res > -1) return res;

            if (b) {
                res = solve(l+1, !b, times+1) + prices[l];
            } else {
                res = solve(l+1, !b, times) - prices[l];
            }

            return res = max(res, solve(l+1, b, times));
        };

        return solve(0, 0, 0);
    }
};
