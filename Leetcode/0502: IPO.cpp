/*
  Idea: Greedily find highest profit when you reach each new capital.
    Because you can only take up to DISTINCT k, you can't take an element multiple times.
    Used a PQ to store the highest at any given point, end if it's ever empty.
    Add elements to the PQ as long as the capital is lower than current w.
*/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        map<int, vector<int>> M;
        for (int i = 0; i < n; i++) {
            M[capital[i]].push_back(profits[i]);
        }

        auto it = M.begin();
        priority_queue<int> pq;
        while (k--) {
            while (it != M.end() && it->first <= w) {
                for (int &elem : it->second) {
                    pq.push(elem);
                }
                it = next(it);
            }
            if (pq.empty()) break;
            w += pq.top();
            pq.pop();
        }

        return w;
    }
};
