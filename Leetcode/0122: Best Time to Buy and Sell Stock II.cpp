class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> memo(n, vector<int>(2, -1));
        function<int(int, bool)> solve = [&] (int l, bool b) {
            if (l == n) return 0;
            auto &res = memo[l][b];
            if (res > -1) return res;

            res = solve(l+1, !b) + prices[l] * (b ? 1 : -1);
            return res = max(res, solve(l+1, b));
        };

        return solve(0, 0);
    }
};
