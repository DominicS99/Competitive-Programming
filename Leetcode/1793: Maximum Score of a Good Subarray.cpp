class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int l = k, r = k;
        int res = nums[k], curr = nums[k];
        while (l > 0 || r < n-1) {
            int nextL = (l ? nums[l-1] : 0);
            int nextR = (r == n ? 0 : nums[r+1]);
            if (nextL > nextR) {
                curr = min(curr, nums[--l]);
            } else {
                curr = min(curr, nums[++r]);
            }
            res = max(res, curr * (r-l+1));
        }
        return res;
    }
};