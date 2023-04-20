class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> memo(n, vector<vector<int>>(k, vector<int>(2, -1)));
        function<int (int, int, bool)> solve = [&] (int l, int times, bool b) {
            if (l == n) return 0;
            if (times == k) return 0;
            auto &res = memo[l][times][b];
            if (res > -1) return res;

            if (b) res = solve(l+1, times+1, !b) + prices[l];
            else res = solve(l+1, times, !b) - prices[l];

            return res = max(res, solve(l+1, times, b));
        };

        return solve(0, 0, 0);
    }
};
