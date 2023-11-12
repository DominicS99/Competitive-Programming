class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int k = __builtin_popcount(num2);
        int res = 0;
        if (k == 0) return res;

        for (int i = 30; i >= 0; i--) {
            if (num1 & (1<<i)) {
                res |= (1<<i);
                if (--k == 0) return res;
            }
        }

        for (int i = 0; i <= 30; i++) {
            if (num1 & (1<<i)) continue;
            res |= (1<<i);
            if (--k == 0) break;
        }
        return res;
    }
};