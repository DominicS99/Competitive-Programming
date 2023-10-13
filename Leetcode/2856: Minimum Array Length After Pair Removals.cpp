class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto &x : nums) m[x]++;
        
        priority_queue<int> pq;
        for (auto &[x, v] : m) pq.push(v);
        
        while (pq.size() > 1) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            if (a != 1) pq.push(a-1);
            if (b != 1) pq.push(b-1);
        }
        
        if (pq.empty()) return 0;
        return pq.top();
    }
};