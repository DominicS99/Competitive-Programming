class Solution {
public:
    int reverse(int x) {
        int res = 0;
        for (; x; x /= 10) {
            if (res > INT_MAX/10 || res < INT_MIN/10) return 0;
            res = res*10 + x%10;
        }
        return res;
    }
};