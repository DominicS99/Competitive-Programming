typedef pair<int, int> pii;
typedef pair<int, pii> p3i;
typedef pair<int, p3i> p4i;

class Solution {
public:
    bool alreadyTaken(int keys, char key) {
        key = tolower(key);
        return keys & (1<<(key-'a'));
    }

    int shortestPathAllKeys(vector<string>& grid) {
        vector<int> dir = {1, 0, -1, 0, 1};
        int k = 0, startX, startY;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] >= 'a' && grid[i][j] <= 'f') k++;
                if (grid[i][j] == '@') {
                    grid[i][j] = '.';
                    startX = i, startY = j;
                }
            }
        }

        int lim = 1<<k;
        vector<vector<vector<int>>> dist(m, vector<vector<int>>(n, vector<int>(lim, 1e9)));
        dist[startX][startY][0] = 0;

        priority_queue<p4i, vector<p4i>, greater<p4i>> pq;
        pq.push({0, {0, {startX, startY}}});
        while (!pq.empty()) {
            auto [d, info] = pq.top(); pq.pop();
            auto &[keys, coords] = info;
            auto &[x, y] = coords;
            if (keys == lim-1) return d;
            
            for (int i = 0; i < 4; i++) {
                int r = x + dir[i];
                int c = y + dir[i+1];

                if (r < 0 || c < 0 || r >= m || c >= n) continue;
                if (grid[r][c] == '#') continue;
                if (grid[r][c] == '.' || alreadyTaken(keys, grid[r][c])) {
                    if (dist[r][c][keys] <= dist[x][y][keys] + 1) continue;
                    dist[r][c][keys] = dist[x][y][keys] + 1;
                    pq.push({dist[r][c][keys], {keys, {r, c}}});
                } else if (grid[r][c] >= 'a' && grid[r][c] <= 'f') {
                    int newKey = keys + (1<<(grid[r][c]-'a'));
                    if (dist[r][c][newKey] <= dist[x][y][keys] + 1) continue;
                    dist[r][c][newKey] = dist[x][y][keys] + 1;
                    pq.push({dist[r][c][newKey], {newKey, {r, c}}});
                }
            }
        }
        return -1;
    }
};