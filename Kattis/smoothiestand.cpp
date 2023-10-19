#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int k, r; cin >> k >> r;
    vector<ll> d(k);
    for (auto &it : d) cin >> it;

    ll x, price, res = 0;
    while (r--) {
        ll count = 1e9;
        for (int i = 0; i < k; i++) {
            cin >> x;
            if (!x) continue;
            count = min(count, d[i]/x);
        }
        cin >> price;
        res = max(res, count*price);
    }
    cout << res << "\n";
    return 0;
}