class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n, 0), d(n, 0);

        int res = -1;
        function<void (int)> dfs = [&] (int i) {
            vis[i] = 1;
            if (edges[i] == -1 || vis[edges[i]] == 2) {
                vis[i] = 2;
                return;
            } 
            if (vis[edges[i]]) {
                res = max(res, d[i] + 1 - d[edges[i]]);
                vis[i] = 2;
                return;
            }

            d[edges[i]] = d[i] + 1;
            dfs(edges[i]);
            vis[i] = 2;
        };

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            d[i] = 1;
            dfs(i);
        }

        return res;
    }
};
