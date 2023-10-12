#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int t, m, n, x;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        int bGod = -1, bMech = -1;
        for (int i = 0; i < m; i++) {
            cin >> x;
            bGod = max(bGod, x);
        }
        for (int i = 0; i < n; i++) {
            cin >> x;
            bMech = max(bMech, x);
        };

        if (bGod < bMech) {
            cout << "MechaGodzilla" << endl;
        } else {
            cout << "Godzilla" << endl;
        }
    }

    return 0;
}