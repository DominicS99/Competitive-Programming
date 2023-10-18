class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int idiff, int vdiff) {
        int n = nums.size();
        vector<int> low(n+1), high(n+1);
        low[0] = 0, high[0] = 0;
        for (int i = idiff; i < n; i++) {
            low[i+1] = (nums[i-idiff] < nums[low[i]] ? i-idiff : low[i]);
            high[i+1] = (nums[i-idiff] > nums[high[i]] ? i-idiff : high[i]);
            if (nums[i] - nums[low[i+1]] >= vdiff) return {i, low[i+1]};
            if (nums[high[i+1]] - nums[i] >= vdiff) return {high[i+1], i};
        }

        return {-1, -1};
    }
};