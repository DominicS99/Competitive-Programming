class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size(), highLen = 0;
        for (auto &x : piles) highLen = max(highLen, (int)x.size());
        highLen = min(highLen, k) + 1;
        
        int memo[n][highLen][k];
        memset(memo, -1, sizeof(memo));

        function<int (int, int, int)> solve = [&] (int i, int l, int coins) {
            if (i == n || coins == k) return 0;
            auto &res = memo[i][l][coins];
            if (res > -1) return res;

            int a = solve(i+1, 0, coins);
            int b = 0;
            if (l < piles[i].size()) b = solve(i, l+1, coins+1) + piles[i][l];

            return res = max(a, b);
        };

        return solve(0, 0, 0);
    }
};
