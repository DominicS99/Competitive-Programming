typedef long long LL;
class Solution {
public:
    int arrangeCoins(int n) {
        int l = 2, r = n;
        while (l < r) {
            LL m = l + (r-l)/2;
            LL solve = (m*(m+1))/2;
            if (solve <= n) {
                l = m+1;
            } else {
                r = m;
            }
        }
        return l-1;
    }
};
