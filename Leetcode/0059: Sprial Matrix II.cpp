typedef pair<int,int> pii;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int m = n*n;
        vector<int> dir = {0, 1, 0, -1, 0};
        vector<vector<int>> grid(n, vector<int>(n, 0));

        int x = 0, y = 0;
        grid[x][y] = 1;
        int d = 0;
        for (int i = 2; i <= m; i++) {
            int r = x + dir[d];
            int c = y + dir[d+1];
            if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] > 0) {
                d = (d+1)%4;
                i--;
            } else {
                grid[r][c] = i;
                x = r;
                y = c;
            }
        }

        return grid;
    }
};