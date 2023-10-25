class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) return 0;
        int m = 1<<(n-2);
        return (k > m ? !kthGrammar(n, k-m) : kthGrammar(n-1, k));
    }
};