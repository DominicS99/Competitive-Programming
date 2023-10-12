class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& grid) {
        vector<int> dir = {0, 1, 0, -1, 0};
        int m = grid.size(), n = grid[0].size();
        int tot = m*n;
        vector<int> res(tot);

        int x = 0, y = -1;
        int d = 0;
        for (int i = 0; i < tot; i++) {
            int r = x + dir[d];
            int c = y + dir[d+1];

            if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 101) {
                d = (d+1)%4;
                i--;
            } else {
                res[i] = grid[r][c];
                grid[r][c] = 101;
                x = r;
                y = c;
            }
        }
        return res;
    }
};