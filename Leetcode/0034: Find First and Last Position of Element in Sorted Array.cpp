class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n;

        while (l < r) {
            int m = l + (r-l)/2;

            if (nums[m] < target) {
                l = m+1;
            } else {
                r = m;
            }
        }

        if (l == n || nums[l] != target) return {-1, -1};

        int l2 = l, r2 = n;
        while (l2 < r2) {
            int m = l2 + (r2-l2)/2;

            if (nums[m] > target) {
                r2 = m;
            } else {
                l2 = m+1;
            }
        }
        return {l, r2-1};
    }
};
