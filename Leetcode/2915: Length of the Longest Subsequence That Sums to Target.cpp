class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        int memo[n+1][target+1];
        memset(memo, -1, sizeof(memo));
        function<int(int, int)> solve = [&] (int i, int k) {
            auto &res = memo[i][k];
            if (res != -1) return res;
            if (k == target) return res = 0;
            if (i == n) return res = -1e9;
            
            res = solve(i+1, k);
            if (k+nums[i] <= target) res = max(res, 1 + solve(i+1, k+nums[i]));
            return res;
        };
        
        int res = solve(0, 0);
        if (res < 0) return -1;
        return res;
    }
};