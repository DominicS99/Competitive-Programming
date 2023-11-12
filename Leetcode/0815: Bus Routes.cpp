class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        int n = routes.size();
        vector<vector<int>> al(n);
        unordered_set<int> starts, stops;
        for (int i = 0; i < n; i++) {
            unordered_set<int> s;
            for (auto &x : routes[i]) {
                s.insert(x);
                if (x == source) starts.insert(i);
                if (x == target) stops.insert(i);
            }
            for (int j = i+1; j < n; j++) {
                for (auto &x : routes[j]) {
                    if (!s.count(x)) continue;
                    al[i].push_back(j);
                    al[j].push_back(i);
                    break;
                }
            }
        }

        vector<int> vis(n, 0);
        queue<int> q;
        for (auto &x : starts) {
            vis[x] = 1;
            q.push(x);
        }

        int res = 1;
        while (!q.empty()) {
            queue<int> newQ;
            while (!q.empty()) {
                auto u = q.front(); q.pop();
                if (stops.count(u)) return res;
                for (auto &v : al[u]) {
                    if (vis[v]) continue;
                    vis[v] = 1;
                    newQ.push(v);
                }
            }
            swap(q, newQ);
            res++;
        }
        return -1;
    }
};