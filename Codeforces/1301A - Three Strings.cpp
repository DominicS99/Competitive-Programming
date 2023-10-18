#include <iostream>
using namespace std;

int main() {
    string a, b, c;
    int _t; cin >> _t;
    while (_t--) {
        bool f = true;
        cin >> a >> b >> c;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == c[i] || b[i] == c[i]) continue;
            f = false;
            break;
        }
        cout << (f ? "YES" : "NO") << "\n";
    }
    return 0;
}