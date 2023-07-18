class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int n = divisors.size();
        int res = 0, resMin = divisors[0];
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int &x : nums) {
                if (x%divisors[i] == 0) count++;
            }
            if (res < count) {
                res = count;
                resMin = divisors[i];
            } else if (res == count) {
                resMin = min(resMin, divisors[i]);
            }
        }
        return resMin;
    }
};
