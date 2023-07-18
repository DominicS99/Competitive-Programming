typedef pair<int, int> pii;
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pii>> graph(n);
        vector<int> vis(n, 0);
        for (auto &it : connections) {
            graph[it[0]].emplace_back(it[1], 1);
            graph[it[1]].emplace_back(it[0], 0);
        }

        int res = 0;
        queue<int> q;
        q.push(0); vis[0] = 1;
        while (!q.empty()) {
            int i = q.front(); q.pop();
            for (auto [j, f] : graph[i]) {
                if (vis[j]) continue;
                
                if (f) res++;
                q.push(j); vis[j] = 1;
            }
        }
        return res;
    }
};
