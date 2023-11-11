class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        long long res = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < values.size(); i++) {
            for (int j = 0; j < values[i].size(); j++) {
                pq.push(values[i][j]);
            }
        }
        long long i = 1;
        while (!pq.empty()) {
            auto x = pq.top(); pq.pop();
            res += i*x;
            i++;
        }
        return res;
    }
};