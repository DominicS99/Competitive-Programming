class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        for (int i = 0; i < min(n+1, 3); i++) dp[i] = i;
        for (int i = 3; i <= n; i++) dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};