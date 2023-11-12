class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (abs(nums[j] - nums[i]) <= min(nums[i], nums[j])) {
                    res = max(res, (nums[i] ^ nums[j]));
                }
            }
        }
        return res;
    }
};