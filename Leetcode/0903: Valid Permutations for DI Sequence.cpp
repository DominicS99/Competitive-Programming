class Solution {
public:
    int numPermsDISequence(string s) {
        int MOD = 1e9+7;
        int n = s.length();
        int memo[n+1][n+2];
        memset(memo, -1, sizeof(memo));
        vector<int> vis(n+1, 0);

        function<int(int, int)> solve = [&] (int i, int x) {
            auto &res = memo[i][x];
            if (res != -1) return res;
            if (i == n) return res = 1;

            res = 0;
            if (s[i] == 'D') {
                for (int j = x-1; j >= 0; j--) {
                    if (vis[j]) continue;
                    vis[j] = 1;
                    res = (res + solve(i+1, j))%MOD;
                    vis[j] = 0;
                }
            } else {
                for (int j = x+1; j <= n; j++) {
                    if (vis[j]) continue;
                    vis[j] = 1;
                    res = (res + solve(i+1, j))%MOD;
                    vis[j] = 0;
                }
            }
            return res;
        };

        int res = 0;
        for (int i = 0; i <= n; i++) {
            vis[i] = 1;
            res = (res + solve(0, i))%MOD;
            vis[i] = 0;
        }

        return res;
    }
};