typedef long long LL;
class Solution {
public:
    LL MOD = 1e9+7;
    int numWays(vector<string>& words, string target) {
        int x = words[0].length(), y = target.length();
        int memo[x][y];
        memset(memo, -1, sizeof(memo));

        int n = words.size();
        LL freq[x][26];
        memset(freq, 0, sizeof(freq));
        for (auto &w : words) {
            for (int i = 0; i < w.length(); i++) {
                freq[i][w[i]-'a']++;
            }
        }

        function<int (int, int)> solve = [&] (int l, int r) {
            if (r == y) return 1;
            if (l == x) return 0;
            auto &res = memo[l][r];
            if (res > -1) return res;

            LL a = solve(l+1, r);
            LL b = (solve(l+1, r+1) * freq[l][target[r]-'a'])%MOD;

            return res = (a+b)%MOD;
        };

        return solve(0, 0);
    }
};
