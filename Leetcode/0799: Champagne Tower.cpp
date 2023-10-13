class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double memo[query_row+1][query_glass+1];
        memset(memo, -1, sizeof(memo));

        function<double(int, int)> solve = [&] (int i, int k) {
            auto &res = memo[i][k];
            if (res > -1) return res;
            if (i == query_row && k == query_glass) {
                return res = poured;
            }
            if (i == query_row || i < k) {
                return res = 0.0;
            }

            res = max(0.0, (solve(i+1, k) - 1) / 2);
            if (k != query_glass) res += max(0.0, (solve(i+1, k+1) - 1) / 2);
            return res;
        };

        return min(1.0, solve(0, 0));
    }
};