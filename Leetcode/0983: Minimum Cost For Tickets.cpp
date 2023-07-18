class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days[days.size()-1] + 1;
        vector<int> dp(n);
        dp[0] = 0;

        int l = 0;
        for (int i = 1; i < n; i++) {
            if (days[l] != i) {
                dp[i] = dp[i-1];
            } else {
                dp[i] = min({dp[i-1] + costs[0], 
                    dp[max(0, i-7)] + costs[1], 
                    dp[max(0, i-30)] + costs[2]});
                l++;
            }
        }

        return dp[n-1];
    }
};
