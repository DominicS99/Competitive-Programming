typedef pair<int, int> pii;
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        int i = 0;
        for (auto &row : mat) {
            pq.emplace(accumulate(row.begin(), row.end(), 0), i++);
        }

        vector<int> res;
        while (k--) {
            auto [x, y] = pq.top(); pq.pop();
            res.push_back(y);
        }
        return res;
    }
};
