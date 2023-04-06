typedef pair<int, int> pii;

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        vector<int> dir = {1, 0, -1, 0, 1};
        int m = grid.size(), n = grid[0].size();

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) continue;

                function<bool (int, int)> bfs = [&] (int i, int j) {
                    bool f = 1;
                    queue<pii> q;
                    grid[i][j] = 1;
                    q.emplace(i, j);
                    while (!q.empty()) {
                        auto [x, y] = q.front(); q.pop();
                        for (int i = 0; i < 4; i++) {
                            int r = x + dir[i];
                            int c = y + dir[i+1];

                            if (r < 0 || c < 0 || r >= m || c >= n) {
                                f = 0;
                                continue;
                            };
                            if (grid[r][c]) continue;
                            grid[r][c] = 1;
                            q.emplace(r, c);
                        }
                    }
                    return f;
                };

                res += bfs(i, j);
            }
        }
        return res;
    }
};
