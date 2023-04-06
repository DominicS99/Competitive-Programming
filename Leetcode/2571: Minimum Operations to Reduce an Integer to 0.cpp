class Solution {
public:
    int minOperations(int n) {
        int res = 1;
        while (n > 1) {
            if ((n & 3) == 1) {
                res++;
            } else if ((n & 3) == 3) {
                n++;
                res++;
            }
            n = n>>1;
        }
        return res;
    }
};
