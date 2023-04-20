class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = 1e9, res = 0;
        for (int &p : prices) {
            low = min(low, p);
            res = max(res, p-low);
        }
        return res;
    }
};
