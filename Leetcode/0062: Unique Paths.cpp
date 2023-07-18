class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m+1, vector<int>(n+1, 0));
        grid[1][0] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
        }
        return grid[m][n];
    }
};
