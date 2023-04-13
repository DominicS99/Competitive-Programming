class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num;
        while (l < r) {
            int m = l + (r-l)/2;
            if (m < num/m) {
                l = m+1;
            } else {
                r = m;
            }
        }
        return l == num*1.0/l;
    }
};
