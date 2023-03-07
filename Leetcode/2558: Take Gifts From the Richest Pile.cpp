class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for (int g : gifts) pq.push(g);

        while (k--) {
            int curr = pq.top();
            pq.pop();
            pq.push(floor(sqrt(curr)));
        }

        long long res = 0;
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }

        return res;
    }
};
