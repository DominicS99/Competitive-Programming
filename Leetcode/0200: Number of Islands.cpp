/*
  Useful as an intro / lesson for DFS
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dir = {1, 0, -1, 0, 1};

        vector<vector<bool>> visited(m, vector<bool>(n, 0));

        function <void (int, int)> dfs = [&] (int x, int y) {
            visited[x][y] = 1;

            for (int i = 0; i < 4; i++) {
                int r = x + dir[i];
                int c = y + dir[i+1];

                if (r < 0 || c < 0 || r >= m || c >= n) continue;
                if (visited[r][c] == 1) continue;
                if (grid[r][c] == '0') continue;
                dfs(r, c);
            }

            return;
        };

        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 1 || grid[i][j] == '0') continue;
                result++;
                dfs(i, j);
            }
        }

        return result;
    }
};
