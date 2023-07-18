class Solution {
public:
    int m, n, MOD = 1e9+7;
    vector<vector<int>> sums;
    vector<vector<vector<int>>> memo;

    bool hasApples(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1] + sums[row1][col1] - sums[row2+1][col1] - sums[row1][col2+1];
    }

    int solve(int x, int y, int k) {
        if (memo[x][y][k] > -1) return memo[x][y][k];
        if (!k) return hasApples(x, y, m-1, n-1);

        auto & curr = memo[x][y][k] = 0;
        for (int r = x; r < m-1; r++) {
            if (hasApples(x, y, r, n-1)) {
                curr += solve(r+1, y, k-1);
                curr %= MOD;
            }
        }
        for (int c = y; c < n-1; c++) {
            if (hasApples(x, y, m-1, c)) {
                curr += solve(x, c+1, k-1);
                curr %= MOD;
            }
        }
        return curr;
    }

    int ways(vector<string>& pizza, int k) {
        m = pizza.size(), n = pizza[0].size();
        sums.assign(m+1, vector<int>(n+1, 0));
        memo.assign(m, vector<vector<int>>(n, vector<int>(k, -1)));
        memo[m-1][n-1][k-1] = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sums[i][j] = sums[i][j-1] + sums[i-1][j] + (pizza[i-1][j-1] == 'A') - sums[i-1][j-1];
            }
        }
        return solve(0, 0, k-1);
    }
};
