/*
  So this first solution works because you can figure out that it's never palindromic...ok
*/

// class Solution {
// public:
//     bool isStrictlyPalindromic(int n) {
//         return false;
//     }
// }

class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        int base = 2;
        while (base+2 <= n) {
            vector<int> curr;
            int temp = n;
            while (temp > 0) {
                curr.push_back(temp%base);
                temp /= base;
            }
            int l = 0, r = curr.size()-1;
            while (l < r) {
                if (curr[l] != curr[r]) return false;
                l++, r--;
            }
            base++;
        }
        return true;
    }
};
