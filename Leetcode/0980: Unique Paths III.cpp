/*
  - Find unique paths, can traverse all 4 directions (DFS)
  - Must visit all spaces that aren't obstacles (Keep track of visited or count all spaces visited)
*/

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
       // Vars
        vector<int> dir = {0, 1, 0, -1, 0};
        int m = grid.size(), n = grid[0].size();
        int res = 0, count = 0, total = m*n-2;
        
      // DFS function
        function<void(int,int)> dfs = [&](int x, int y) {
            for (int i = 0; i < 4; i++) {
                int r = x + dir[i];
                int c = y + dir[i+1];

                if (r < 0 || c < 0 || r >= m || c >= n) continue;
                if (grid[r][c] == 2 && count == total) res++;
                if (grid[r][c] == 0) {
                    grid[r][c] = -1;
                    count++;
                    dfs(r, c);
                    grid[r][c] = 0;
                    count--;
                }
            }
        };

       // Traverse grid once to find starting space and # of obstacles
        int starti, startj;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    starti = i;
                    startj = j;
                } else if (grid[i][j] == -1) {
                    total--;
                }
            }
        }

      // Start DFS
        dfs(starti, startj);

        return res;
    }
};
