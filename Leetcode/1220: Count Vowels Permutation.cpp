typedef long long ll;
class Solution {
public:
    int countVowelPermutation(int n) {
        int MOD = 1e9+7;
        ll memo[n+1][5];
        memset(memo, -1, sizeof(memo));

        function<ll(int, int)> solve = [&] (int i, int k) {
            auto &res = memo[i][k];
            if (res != -1) return res;
            if (i == n-1) return res = 1;

            if (k == 0) {
                return res = solve(i+1, 1);
            } else if (k == 1) {
                return res = (solve(i+1, 0) + solve(i+1, 2))%MOD;
            } else if (k == 2) {
                return res = (solve(i+1, 0) + solve(i+1, 1) + solve(i+1, 3) + solve(i+1, 4))%MOD;
                
            } else if (k == 3) {
                return res = (solve(i+1, 2) + solve(i+1, 4))%MOD;
            }
            return res = solve(i+1, 0);
        };

        int res = 0;
        for (int i = 0; i < 5; i++) {
            res = (res + solve(0, i))%MOD;
        }

        return res;
    }
};