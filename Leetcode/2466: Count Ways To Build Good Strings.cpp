class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int MOD = 1e9+7;
        int n = high+1;
        int res = 0;

        vector<int> counts(n, 0);
        counts[0] = 1;
        for (int i = 1; i < n; i++) {
            int a = i<zero ? 0 : counts[i-zero];
            int b = i<one ? 0 : counts[i-one];
            counts[i] = (a+b)%MOD;

            if (low > i) continue;
            res += counts[i];
            res %= MOD;
        }

        return res;
    }
};
