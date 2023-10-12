class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        for (int l = 0; l < n; l++) {
            while (l < n && nums[l] == val) {
                swap(nums[l], nums[--n]);
            }
        }
        return n;
    }
};