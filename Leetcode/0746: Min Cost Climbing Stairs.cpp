class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int memo[n+1];
        memset(memo, -1, sizeof(memo));
        
        function<int(int)> solve = [&] (int i) {
            auto &res = memo[i];
            if (res != -1) return res;
            if (i == n) return res = 0;
            
            res = solve(i+1);
            if (i+2 <= n) res = min(res, solve(i+2));
            return res += cost[i];
        };

        return min(solve(0), solve(1));
    }
};