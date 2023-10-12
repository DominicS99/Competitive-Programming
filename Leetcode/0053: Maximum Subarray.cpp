class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int a = 0, b = nums[0];
        for (int &x : nums) {
            a = max(a, 0) + x;
            b = max(b, a);
        }
        return b;
    }
};