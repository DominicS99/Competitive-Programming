class Solution {
public:
    int countDigits(int num) {
        int res = 0, curr = num;

        while (curr) {
            res += (num % (curr%10)) ? 0 : 1;
            curr /= 10;
        }
        return res;
    }
};
