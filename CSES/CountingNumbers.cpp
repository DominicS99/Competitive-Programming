#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    string num1, num2; cin >> num1 >> num2;

    int n = num2.length();
    while (num1.length() < n) num1 = "0" + num1;
    ll memo[n+1][2][2][2][11];
    memset(memo, -1, sizeof(memo));

    function<ll(int, bool, bool, bool, int)> solve = [&] (int i, bool tLow, bool tHigh, bool lz, int x) {
        auto &res = memo[i][tLow][tHigh][lz][x];
        if (res > -1) return res;
        if (i == n) return res = 1;
  
        int l = (tLow) ? num1[i] - '0' : 0;
        int r = (tHigh) ? num2[i] - '0' : 9;
  
        ll temp = 0;
        for (int j = l; j <= r; j++) {
            if (j == x && !lz) continue;
            bool ccl = tLow & (j == l);
            bool cch = tHigh & (j == r);
            bool clz = (j == 0 ? lz : 0);
            ll next = solve(i+1, ccl, cch, clz, j);
            temp += next;
        }
        return res = temp;
    };

    cout << solve(0, 1, 1, 1, 10) << "\n";
    return 0;
}