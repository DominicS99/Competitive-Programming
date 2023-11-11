typedef long long ll;

class Solution {
public:
    int MOD = 1e9+7;
    int stringCount(int n) {
        ll memo[n+1][16];
        memset(memo, -1, sizeof(memo));
        
        function<ll(int, int)> solve = [&] (int i, int k) {
            auto &res = memo[i][k];
            if (res != -1) return res;
            if (i == n) return res = (k == 15);
            
            ll temp = 0;
            for (int j = 0; j <= 25; j++) {
                int newK = k;
                if (j+'a' == 'l') {
                    newK |= 1;
                } else if (j+'a' == 't') {
                    newK |= 8;
                } else if (j+'a' == 'e') {
                    if (newK & 2) {
                        newK |= 4;
                    } else {
                        newK |= 2;
                    }
                }
                ll next = solve(i+1, newK);
                temp = (temp + next)%MOD;
            }
            return res = temp;
        };
        
        return solve(0, 0);
    }
};