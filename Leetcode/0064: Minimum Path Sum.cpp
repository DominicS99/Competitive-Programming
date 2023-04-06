class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> res(m+1, vector<int>(n+1, 1e9));
        res[0][1] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i+1][j+1] = min(res[i][j+1], res[i+1][j]) + grid[i][j];
            }
        }
        return res[m][n];
    }
};
