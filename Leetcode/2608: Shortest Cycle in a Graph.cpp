class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> al(n);
        for (auto &it : edges) {
            al[it[0]].push_back(it[1]);
            al[it[1]].push_back(it[0]);
        }
        
        vector<int> dist;
        int res = 1e9;
        function<void (int)> bfs = [&] (int i) {
            dist.assign(n, 1e9);
            dist[i] = 0;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int x = q.front(); q.pop();
                for (int y : al[x]) {
                    if (dist[y] == 1e9) {
                        dist[y] = dist[x]+1;
                        q.push(y);
                    } else if (dist[y] >= dist[x]) {
                        res = min(res, dist[x] + dist[y] + 1);
                    }
                }
            }
        };
        
        for (int i = 0; i < n; i++) bfs(i);
        return res == 1e9 ? -1 : res;
    }
};
