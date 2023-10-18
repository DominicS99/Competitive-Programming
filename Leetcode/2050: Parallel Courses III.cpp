/**
 * @brief Standard top sort, but with PQ to find latest time a course can start
 * 
 */

typedef pair<int, int> pii;
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> pSize(n+1, 0);
        vector<vector<int>> al(n+1);
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        for (auto &prereq : relations) {
            int from = prereq[0], to = prereq[1];
            al[from].push_back(to);
            pSize[to]++;
        }

        for (int i = 1; i <= n; i++) {
            if (!pSize[i]) pq.emplace(time[i-1], i);
        }

        int res = 0;
        while (!pq.empty()) {
            auto [t, u] = pq.top(); pq.pop();
            res = max(res, t);
            for (auto &v : al[u]) {
                if (--pSize[v] <= 0) pq.emplace(time[v-1]+t, v);
            }
        }

        return res;
    }
};