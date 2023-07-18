class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> memo(amount+1, 1e9);
        memo[0] = 0;
        for (int &c : coins) {
            int lim = amount+1-c;
            for (int i = 0; i < lim; i++) {
                if (memo[i] == 1e9) continue;
                memo[i+c] = min(memo[i+c], memo[i]+1);
            }
        }
        return memo[amount] == 1e9 ? -1 : memo[amount];
    }
};
