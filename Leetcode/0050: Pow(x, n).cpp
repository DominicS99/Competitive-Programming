class Solution {
public:
    double myPow(double x, long long n) {
        if (n < 0) {x = 1.0/x; n *= -1;}
        double res = 1.0;
        for (; n > 0; n >>= 1, x *= x) if (n%2) res *= x;
        return res;
    }
};