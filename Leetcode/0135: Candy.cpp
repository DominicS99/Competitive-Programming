class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> diff(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]) diff[i] = diff[i-1]+1;
        }

        for (int i = n-1; i > 0; i--) {
            if (ratings[i] < ratings[i-1]) diff[i-1] = max(diff[i-1], diff[i]+1);
        }

        int res = 0;
        for (auto &x : diff) res += x;
        return res;
    }
};