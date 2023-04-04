class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<int> dir = {1, 0, -1, 0, 1};
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) continue;
                for (int d = 0; d < 4; d++) {
                    int r = i + dir[d];
                    int c = j + dir[d+1];
                    
                    if (r < 0 || c < 0 || r >= m || c >= n || !grid[r][c]) res++;
                }
            }
        }
        return res;
    }
};
