typedef long long LL;

class Solution {
public:
    int mySqrt(LL x) {
        LL l = 0, r = x+1;
        while (l+1 != r) {
            LL m = l + (r-l)/2;
            if (x < m*m) r = m;
            else l = m;
        }
        return l;
    }
};
