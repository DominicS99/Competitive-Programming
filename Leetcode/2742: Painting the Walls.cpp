class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        int memo[n+1][n+1];
        memset(memo, -1, sizeof(memo));

        function<int(int, int)> solve = [&] (int i, int t) {
            auto &res = memo[i][t];
            if (res != -1) return res;
            if (t == n) return res = 0;
            if (i == n) return res = 1e9;

            res = solve(i+1, t);
            return res = min(res, solve(i+1, min(n, t+time[i]+1)) + cost[i]);
        };

        return solve(0, 0);
    }
};