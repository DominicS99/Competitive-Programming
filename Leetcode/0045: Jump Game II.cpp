class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n);
        memo[n-1] = 0;
        
        for (int i = n-2; i > -1; i--) {
            int low = INT_MAX;
            for (int j = i+1; j < i+nums[i]+1 && j < n; j++) {
                low = min(low, memo[j]);
            }
            memo[i] = (low == INT_MAX ? INT_MAX : low+1);
        }

        return memo[0];
    }
};
