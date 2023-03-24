class Solution {
public:
    int kthFactor(int n, int k) {
        int r = n/2;
        for (int i = 1; i <= r; i++) {
            if (n%i) continue;
            if (!(--k)) return i;
        }
        return k == 1 ? n : -1;
    }
};
