class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.rbegin(), nums.rend());
        vector<int> res;
        int curr = 0, i = 0;
        while (sum >= curr) {
            curr += nums[i];
            sum -= nums[i];
            res.push_back(nums[i++]);
        }
        return res;
    }
};