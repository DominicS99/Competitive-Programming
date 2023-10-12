#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<ll> d(n);
    for (auto &it : d) cin >> it;

    vector<ll> red(n);
    for (int i = 0; i < n; i++) {
        red[i] = m;
        m = m*2/3;
    }

    ll memo[101][101][2];
    memset(memo, -1, sizeof(memo));

    function<ll(int, int, bool)> solve = [&] (int i, int j, bool canReset) {
        auto &res = memo[i][j][canReset];
        if (res != -1) return res;
        if (i == n) return res = 0;

        res = solve(i+1, j+1, 0) + min(d[i], red[j]);
        if (canReset) {
            res = max(res, solve(i+1, 0, 0));
        } else {
            res = max(res, solve(i+1, max(0, j-1), 1));
        }

        return res;
    };

    cout << solve(0, 0, 0) << endl;
    return 0;
}