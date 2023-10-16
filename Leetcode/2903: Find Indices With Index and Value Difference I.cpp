class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int a, int b) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (abs(i-j) >= a && abs(nums[i]-nums[j]) >= b) return {i, j};
            }
        }
        return {-1, -1};
    }
};