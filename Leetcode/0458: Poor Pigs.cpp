class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int n = buckets, d = minutesToTest/minutesToDie;
        int res = 0;
        while (1) {
            int curr = 1;
            for (int i = 0; i < res; i++) {
                curr *= (d+1);
            }
            if (n-curr <= 0) break;
            res++;
        }
        return res;
    }
};