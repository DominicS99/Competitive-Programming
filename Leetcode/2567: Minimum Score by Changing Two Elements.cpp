class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size()-1;
        sort(nums.begin(), nums.end());
        
        int res = 1e9;
        for (int i = 0; i < 3; i++) {
            res = min(res, nums[n-i]-nums[2-i]);
        }

        return res;
    }
};
