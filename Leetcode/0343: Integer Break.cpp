class Solution {
public:
    int integerBreak(int n) {
        if (n < 4) return n-1;
        int res = 1;
        if (n % 3 == 1) {
            res = 4;
            n -= 4;
        }
        if (n % 3 == 2) {
            res = 2;
            n -= 2;
        }
        return res * pow(3, n/3);
    }
};