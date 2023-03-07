typedef pair<int, int> pii;

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        vector<int> dir = {1, 0, -1, 0, 1};
        int m = grid.size();
        int n = grid[0].size();
        int group = grid[row][col];
        vector<pii> coords;

        // BFS to grab flood fill info, mark visited using -1
        queue<pii> q;
        q.emplace(row, col);
        grid[row][col] = -1;
        while (!q.empty()) {
            pii curr = q.front();
            q.pop();
            bool f = false;

            for (int i = 0; i < 4; i++) {
                int r = curr.first + dir[i];
                int c = curr.second + dir[i+1];

                if (r < 0 || c < 0 || r >= m || c >= n) {
                    f = true;
                    continue;
                }
                if (grid[r][c] == -1) continue;
                if (grid[r][c] != group) {
                    f = true;
                    continue;
                }
                grid[r][c] = -1;
                q.emplace(r, c);
            }

            if (f) coords.push_back(curr);
        }

        // Color all good options, fix marked areas. Could use a 2nd grid to skip the -1 conversions.
        for (auto &it : coords) grid[it.first][it.second] = color;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == -1) grid[i][j] = group;
            }
        }

        return grid;
    }
};
