class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        for (int l = 0, r = nums.size()-1; l < r; ) {
            if (nums[l]%2) {
                swap(nums[l], nums[r--]);
            } else {
                l++;
            }
        }
        return nums;
    }
};