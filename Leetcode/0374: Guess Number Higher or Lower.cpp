/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
 
typedef long long LL;

class Solution {
public:
    int guessNumber(LL n) {
        LL l = 1, r = n+1;
        while (l+1 != r) {
            LL m = l + (r-l)/2;
            int x = guess(m);
            if (x < 0) r = m;
            else if (x > 0) l = m;
            else return m;
        }
        return l;
    }
};
