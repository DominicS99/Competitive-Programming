// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

typedef long long LL;
class Solution {
public:
    int firstBadVersion(LL n) {
        LL l = 0, r = n+1;

        while (l+1 != r) {
            LL m = l + (r-l)/2;

            if (isBadVersion(m)) r = m;
            else l = m;
        }

        return r;
    }
};
