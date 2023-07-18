class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int a = 0, b = 0;
        for (auto &x : position) {
            if (x%2) b++;
            else a++;
        }
        return min(a, b);
    }
};
