typedef tuple<int, int, int> t3i;

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int res = 0;
        priority_queue<t3i> pq;
        for (int i = 0; i < reward1.size(); i++) {
            pq.emplace(reward1[i]-reward2[i], reward1[i], reward2[i]);
        }
        
        while (!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            if (k-- > 0) {
                res += get<1>(curr);
            } else {
                res += get<2>(curr);
            }
        }
        
        return res;
    }
};
