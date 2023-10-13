class Solution {
public:
    int countWays(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = (nums[0] != 0);
        for (int i = 1; i < n; i++) {
            if (nums[i-1] < i && nums[i] > i) res++;
        }
        return res + (nums[n-1] < n);
    }
};