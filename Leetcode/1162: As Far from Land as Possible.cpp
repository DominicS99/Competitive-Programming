typedef pair<int, int> pii;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        vector<int> dir = {1, 0, -1, 0, 1};
        int n = grid.size();
        queue<pii> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) continue;
                q.emplace(i, j);
            }
        }

        int res = 0;
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if (grid[x][y] > 1) res = grid[x][y];

            for (int i = 0; i < 4; i++) {
                int r = x + dir[i];
                int c = y + dir[i+1];

                if (r < 0 || c < 0 || r >= n || c >= n) continue;
                if (grid[r][c]) continue;

                grid[r][c] = grid[x][y] + 1;
                q.emplace(r, c);
            }
        }

        return res-1;
    }
};
