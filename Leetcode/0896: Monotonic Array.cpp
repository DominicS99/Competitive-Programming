class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool a = true, b = true;
        for (int i = 0; i+1 < nums.size(); i++) {
            if (nums[i] > nums[i+1]) a = false;
            else if (nums[i] < nums[i+1]) b = false;

            if (!a & !b) return false;
        }
        return true;
    }
};