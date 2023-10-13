class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        int low = 1e9, index = 0;
        for (int i = 0; i < n; i++) {
            if (low > nums[i]) {
                index = i;
                low = nums[i];
            }
        }
        int res = (n-index)%n, prev = nums[index];
        index = (index+1)%n;
        for (int i = 1; i < n; i++) {
            if (nums[index] < prev) return -1;
            prev = nums[index];
            index = (index+1)%n;
        }
        return res;
    }
};