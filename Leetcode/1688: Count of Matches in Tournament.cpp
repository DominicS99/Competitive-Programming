class Solution {
public:
    int numberOfMatches(int n) {
        int res = 0;
        while (n > 1) {
            if (n%2) {
                n++;
                res--;
            }
            res += n/2;
            n/=2;
        }
        return res;
    }
};
