// From scratch for POTD 10/28/24
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int memo[m+1][n+1];
        memset(memo, -1, sizeof(memo));
        function<int(int, int)> solve = [&] (int r, int c) {
            auto &res = memo[r][c];
            if (res != -1) return res;

            res = 0;
            if (c == n-1) return res = 0;
            
            if (r != 0 && grid[r][c] < grid[r-1][c+1]) res = max(res, solve(r-1, c+1) + 1);
            if (grid[r][c] < grid[r][c+1]) res = max(res, solve(r, c+1) + 1);
            if (r != m-1 && grid[r][c] < grid[r+1][c+1]) res = max(res, solve(r+1, c+1) + 1);
            return res;
        };

        int res = 0;
        for (int i = 0; i < m; i++) {
            res = max(res, solve(i, 0));
        }
        return res;
    }
};


// Code from 5/13/24
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        vector<int> dirX = {-1, 0, 1};
        vector<int> dirY = {1, 1, 1};
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        int memo[m+1][n+1];
        memset(memo, -1, sizeof(memo));
        
        function<int (int, int)> solve = [&] (int a, int b) {
            int & curr = memo[a][b];
            if (curr > -1) return curr;
            int temp = 0;
            for (int i = 0; i < 3; i++) {
                int r = a + dirX[i];
                int c = b + dirY[i];
                if (r < 0 || c < 0 || r >= m || c >= n) continue;
                if (grid[r][c] <= grid[a][b]) continue;
                
                temp = max(temp, solve(r,c)+1);
            }
            return curr = temp;
        };
        
        for (int j = 0; j < m; j++) {
            res = max(res, solve(j, 0));
        }
        return res;
    }
};
