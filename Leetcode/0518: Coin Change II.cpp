class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> count(amount+1, 0);
        count[0] = 1;
        for (int c : coins) {
            int lim = amount+1-c;
            for (int i = 0; i < lim; i++) {
                count[i+c] += count[i];
            }
        }
        return count[amount];
    }
};
