class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int MOD = 1e9+7;
        int n = board.size();
        vector<int> res(2, 0);
        
        // Converted board to integers and stored in input
        vector<vector<int>> input(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') input[i][j] = -1;
                else if (board[i][j] == 'S' || board[i][j] == 'E') input[i][j] = 0;
                else input[i][j] = board[i][j] - '0';
            }
        }

        // Copied input to grid, then greedily found the max from all paths in O(# of grid elements)
        vector<vector<int>> grid = input;

        for (int i = n-1; i > -1; i--) {
            for (int j = n-1; j > -1; j--) {
                if (i == n-1 && j == n-1) continue;
                if (grid[i][j] < 0) continue;
                int adj;
                
                if (i == n-1) adj = grid[i][j+1];
                else if (j == n-1) adj = grid[i+1][j];
                else adj = max(max(grid[i+1][j], grid[i][j+1]), grid[i+1][j+1]);
                
                grid[i][j] = (adj == -1 ? adj : adj+grid[i][j]);
            }
        }

        // // Input
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << input[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        // // Grid
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        res[0] = max(grid[0][0], 0);

        // This part was jank. Idea is that you need to count the ways you get back to start based on:
        // - Is it possible to reach the previous space using the current grid value + prev input?
      
        // DP is not my strong suit...but I powered through it and found AC
        vector<vector<long long>> memo(n+1, vector<long long>(n+1, 0));
        memo[1][1] = 1;
        for (int r = 1; r <= n; r++) {
            for (int c = 1; c <= n; c++) {
                if (r == 1 && c == 1) continue;
                auto & mCurr = memo[r][c];
                int mUp = memo[r][c-1];
                int mLeft = memo[r-1][c];
                int gCurr = grid[r-1][c-1];
                if (gCurr < 0) continue;

                if (r == 1) {
                    mCurr = grid[r-1][c-2] == gCurr + input[r-1][c-2] ? mUp : 0;
                    continue;
                } else if (c == 1) {
                    mCurr = grid[r-2][c-1] == gCurr + input[r-2][c-1] ? mLeft : 0;
                    continue;
                }

                int up = grid[r-1][c-2];
                int left = grid[r-2][c-1];
                int diag = grid[r-2][c-2];
                int inUp = input[r-1][c-2];
                int inLeft = input[r-2][c-1];
                int inDiag = input[r-2][c-2];
                int mDiag = memo[r-1][c-1];
                
                if (diag > -1 && diag == gCurr + inDiag) mCurr = mDiag;
                else if (left == gCurr + inLeft && up == gCurr + inUp) mCurr = (mLeft + mUp) % MOD;
                else if (up == gCurr + inUp) mCurr = mUp;
                else if (left == gCurr + inLeft) mCurr = mLeft;
            }
        }

        // // memo
        // for (int i = 0; i <= n; i++) {
        //     for (int j = 0; j <= n; j++) {
        //         cout << memo[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        res[1] = memo[n][n];
        return res;
    }
};
