class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) break;

            int l = i+1, r = n-1;
            while (l < r) {
                int curr = nums[l] + nums[r];
                if (nums[i] + curr == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});

                    while (l < r && nums[l] == nums[l+1]) l++;
                    while (l < r && nums[r] == nums[r-1]) r--;
                    l++; r--;
                } else if (nums[i] + curr < 0) {
                    l++;
                } else {
                    r--;
                }
            }

            while (i+1 < n && nums[i] == nums[i+1]) i++;
        }
        return res;
    }
};