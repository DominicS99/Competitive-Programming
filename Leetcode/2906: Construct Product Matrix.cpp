// Modified solution to remove unnecessary checks
int MOD = 12345;
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        long long tot = 1;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n, 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = (res[i][j] * tot) % MOD;
                tot = (tot * grid[i][j]) % MOD;
            }
        }

        tot = 1;
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                res[i][j] = (res[i][j] * tot) % MOD;
                tot = (tot * grid[i][j]) % MOD;
            }
        }
        return res;
    }
};

/**
 * Initial Solution:
 * 
int MOD = 12345;
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        long long tot = 1;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n, 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                tot *= (j ? grid[i][j-1] : grid[i-1][n-1]);
                tot %= MOD;
                res[i][j] = (res[i][j] * tot) % MOD;
            }
        }

        tot = 1;
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (i == m-1 && j == n-1) continue;
                tot *= (j != n-1 ? grid[i][j+1] : grid[i+1][0]);
                tot %= MOD;
                res[i][j] = (res[i][j] * tot) % MOD;
            }
        }
        return res;
    }
};
*/