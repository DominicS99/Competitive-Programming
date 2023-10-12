#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        int n = b.length();
        while (a.length() < n) a = "0" + a;
        pair<ll, ll> memo[n+1][2][2][11];

        function<pair<ll, ll>(int, bool, bool, int)> solve = [&] (int i, bool tLow, bool tHigh, int x) {
            auto &res = memo[i][tLow][tHigh][x];
            auto &[sum, count] = res;
            if (count > -1) return res;
            if (i == n) return res = {x%10, 1};

            int l = (tLow) ? a[i]-'0' : 0;
            int r = (tHigh) ? b[i]-'0' : 9;

            sum = 0, count = 0;
            for (int j = l; j <= r; j++) {
                bool ccl = tLow & (j == l);
                bool cch = tHigh & (j == r);
                auto next = solve(i+1, ccl, cch, j);
                sum += next.first; count += next.second;
            }
            sum += (x%10 * count);
            return res;
        };

        memset(memo, -1, sizeof(memo));
        cout << solve(0, 1, 1, 10).first << endl;
    }
    return 0;
}