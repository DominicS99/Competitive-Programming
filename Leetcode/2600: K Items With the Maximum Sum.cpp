class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int res = min(k, numOnes);
        k -= numOnes + numZeros;
        if (k > 0) return res - k;
        return res;
    }
};

// Fully naive idea, don't have to think too much about this during a contest, but it takes a bit to code.
/*
class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int res = 0;
        while (k--) {
            if (numOnes) {
                res++;
                numOnes--;
            } else if (numZeros) {
                numZeros--;
            } else {
                res--;
                numNegOnes--;
            }
        }
        return res;
    }
};
*/
