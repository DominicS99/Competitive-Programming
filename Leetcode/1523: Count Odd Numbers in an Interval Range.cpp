class Solution {
public:
    int countOdds(int low, int high) {
        int res = (high - low) / 2;
        return low%2 == 1 || high%2 == 1 ? res+1 : res;
    }
};
