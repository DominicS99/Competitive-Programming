class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        int high = 1e5+2;
        vector<int> sums(high, 0);
        for (auto &x : potions) {
            long long temp = ceil(1.0 * success/x);
            if (temp < high) sums[temp]++;
        }
        for (int i = 1; i < sums.size(); i++) {
            sums[i] += sums[i-1];
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = sums[spells[i]];
        }
        
        return res;
    }
};
