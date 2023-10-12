class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return 0;
        long long res = 0;
        for (long long temp = x; temp; temp /= 10) {
            res *= 10;
            res += temp%10;
        }
        return res == x;
    }
};