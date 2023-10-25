class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n), r(n);
        l[0] = nums[0], r[n-1] = nums[n-1];
        for (int i = 1; i < n; i++) {
            l[i] = min(l[i-1], nums[i]);
            r[n-i-1] = min(r[n-i], nums[n-i-1]);
        }

        int res = 1e9;
        for (int i = 1; i+1 < n; i++) {
            if (nums[i] > l[i-1] && nums[i] > r[i]) {
                res = min(res, nums[i] + l[i-1] + r[i]);
            }
        }

        return res == 1e9 ? -1 : res;
    }
};