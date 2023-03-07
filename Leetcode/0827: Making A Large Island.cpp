typedef pair<int, int> pii;

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        vector<int> dir = {1, 0, -1, 0, 1};
        int n = grid.size();
        vector<int> groups;
        int group = 2;

        // BFS to find connected + store counts for each group. +1 initially since the initial spot gets skipped.
        function <void (int, int)> bfs = [&] (int x, int y) {
            int count = 1;
            queue<pii> q;
            q.emplace(x, y);
            while (!q.empty()) {
                pii curr = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int r = curr.first + dir[i];
                    int c = curr.second + dir[i+1];

                    if (r < 0 || c < 0 || r >= n || c >= n) continue;
                    if (grid[r][c] != 1) continue;

                    grid[r][c] = group;
                    q.emplace(r, c);
                    count++;
                }
            }

            groups.push_back(count);
        };

        // When we reach a 0, check all 4 directions around it. Add groups given certain criteria. +1 initially since 0 filps to 1.
        function <int (int, int)> solve = [&] (int x, int y) {
            int count = 1;
            set<int> visited;
            for (int i = 0; i < 4; i++) {
                int r = x + dir[i];
                int c = y + dir[i+1];

                if (r < 0 || c < 0 || r >= n || c >= n) continue;
                int temp = grid[r][c];
                if (!temp) continue;
                if (visited.count(temp)) continue;

                count += groups[temp-2];
                visited.insert(temp);
            }
            return count;
        };

        // Make connected areas into groups using BFS
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 1) continue;
                grid[i][j] = group;
                bfs(i, j);
                group++;
            }
        }

        // Solve the problem at each 0, find the maximum.
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) continue;
                res = max(res, solve(i, j));
            }
        }

        // If there are no 0's, the entire grid must be filled with 1, so just return grid size (n*n).
        return res ? res : n*n;
    }
};
