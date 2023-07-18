class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m+1, vector<int>(n+1, 0));
        res[0][1] = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) continue;
                res[i+1][j+1] = res[i+1][j] + res[i][j+1];
            }
        }
        return res[m][n];
    }
};
