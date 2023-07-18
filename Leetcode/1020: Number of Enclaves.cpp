typedef pair<int, int> pii;
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        vector<int> dir = {1, 0, -1, 0, 1};
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) continue;
                int curr = 1;
                bool f = true;
                queue<pii> q;
                grid[i][j] = 0;
                q.emplace(i, j);
                while (!q.empty()) {
                    auto [x, y] = q.front(); q.pop();
                    for (int i = 0; i < 4; i++) {
                        int r = x + dir[i];
                        int c = y + dir[i+1];

                        if (r < 0 || c < 0 || r >= m || c >= n) {
                            f = false;
                            continue;
                        }
                        if (!grid[r][c]) continue;
                        
                        curr++;
                        grid[r][c] = 0;
                        q.emplace(r, c);
                    }
                }

                if (f) res += curr;
            }
        }
        return res;
    }
};

// Faster runtime by performing less BFS queries
/*
typedef pair<int, int> pii;
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        vector<int> dir = {1, 0, -1, 0, 1};
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        queue<pii> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) continue;
                if (!i || !j || i == m-1 || j == n-1) {
                    grid[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int r = x + dir[i];
                int c = y + dir[i+1];

                if (r < 0 || c < 0 || r >= m || c >= n) continue;
                if (!grid[r][c]) continue;

                grid[r][c] = 0;
                q.emplace(r, c);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) res++;
            }
        }
        return res;
    }
};
*/
