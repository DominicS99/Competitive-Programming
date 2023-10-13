class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        function<bool(long long)> solve = [&] (long long x) {
            for (int i = 0; i < k; i++) {
                long long totCost = 0;
                for (int j = 0; j < n; j++) {
                    long long curr = max((long long)0, (x*composition[i][j])-stock[j]);
                    totCost += (curr * cost[j]);
                    if (totCost > budget) break;
                }
                if (totCost <= budget) return true;
            }
            return false;
        };

        int l = 0, r = INT_MAX;
        while (l < r) {
            int m = l + (r-l)/2;
            if (solve(m)) {
                l = m+1;
            } else {
                r = m;
            }
        }
        return l-1;
    }
};