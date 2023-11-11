#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    int _t; cin >> _t;
    while (_t--) {
        int k; cin >> k;
        ll b, n; cin >> b >> n;
        ll res = 0;
        while (n) {
            res += (n%b) * (n%b);
            n /= b;
        }
        cout << k << " " << res << "\n";
    }
    return 0;
}