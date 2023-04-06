typedef pair<int, int> pii;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<int> dir = {1, 0, -1, 0, 1};
        int m = board.size(), n = board[0].size();

        vector<vector<int>> grid(m+2, vector<int>(n+2, 0));
        for (int i = 1; i < m+1; i++) {
            for (int j = 1; j < n+1; j++) {
                grid[i][j] = board[i-1][j-1] == 'X';
            }
        }

        queue<pii> q;
        grid[0][0] = 2;
        q.emplace(0, 0);
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int r = x + dir[i];
                int c = y + dir[i+1];

                if (r < 0 || c < 0 || r >= m+2 || c >= n+2) continue;
                if (grid[r][c]) continue;

                grid[r][c] = 2;
                q.emplace(r, c);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i+1][j+1]) board[i][j] = 'X';
            }
        }
    }
};
