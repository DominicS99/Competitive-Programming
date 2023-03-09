class Solution {
public:
    int passThePillow(int n, int time) {
        return (time / (n-1)) % 2 ? n - (time % (n-1)) : (time % (n-1)) + 1;
    }
};

/*
        int div = time / (n-1);
        int rem = time % (n-1);
        return div % 2 ? n-rem : rem+1;
*/
