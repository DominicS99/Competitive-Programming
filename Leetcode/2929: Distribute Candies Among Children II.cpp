class Solution {
public:
    long long distributeCandies(int n, int limit) {
        if (limit*3 < n) return 0;
        long long res = 0;
        for (int i = 0; i <= min(n, limit); i++) {
            int curr = n-i;
            if (limit*2 < curr) continue;
            res += curr+1 - (max(0, (curr-limit)*2));
        }
        return res;
    }
};