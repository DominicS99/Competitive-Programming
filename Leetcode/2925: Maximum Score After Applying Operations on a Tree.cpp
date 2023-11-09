typedef long long ll;
class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<int>> al(n);
        for (auto &e : edges) {
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }

        ll memo[n+1][2];
        memset(memo, -1, sizeof(memo));
        vector<int> vis(n, 0);
        vis[0] = 1;
        function<ll(int, int)> solve = [&] (int u, int f) {
            auto &res = memo[u][f];
            if (res != -1) return res;

            res = (f ? values[u] : 0);
            for (auto &v : al[u]) {
                if (vis[v]) continue;
                vis[v] = 1;
                res += solve(v, 1);
                vis[v] = 0;
            }
            
            if (!f) {
                int check = 0;
                ll temp = values[u];
                for (auto &v : al[u]) {
                    if (vis[v]) continue;
                    check++;
                    vis[v] = 1;
                    temp += solve(v, 0);
                    vis[v] = 0;
                }
                if (!check) return res;
                res = max(res, temp);
            }
            return res;
        };

        return solve(0, 0);
    }
};