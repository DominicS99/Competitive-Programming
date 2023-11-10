class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> res;
        unordered_map<int, vector<int>> m;
        for (auto &it : adjacentPairs) {
            m[it[0]].push_back(it[1]);
            m[it[1]].push_back(it[0]);
        }
        for (auto &[x, c] : m) {
            if (c.size() == 1) {
                res.push_back(x);
                int prev = x;
                queue<int> q; q.push(x);
                while (!q.empty()) {
                    int u = q.front(); q.pop();
                    for (auto &v : m[u]) {
                        if (prev == v) continue;
                        res.push_back(v);
                        prev = u;
                        q.push(v);
                        break;
                    }
                }
                break;
            }
        }
        return res;
    }
};