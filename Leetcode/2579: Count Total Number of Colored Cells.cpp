class Solution {
public:
    long long coloredCells(int n) {
        long long res = 1;
        for (int i = 2; i <= n; i++) {
            res += (i-1)*4;
        }
        return res;
    }
};

// O(1) optimization
/*
typedef long long ll;

class Solution {
public:
    ll coloredCells(int n) {
        return (ll)(n) * (n-1) * 2 + 1;
    }
};
*/
