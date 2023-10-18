#include <iostream>
using namespace std;

int main() {
    int _t; cin >> _t;
    while (_t--) {
        bool f = false;
        long long n, k;
        cin >> n >> k;
        if (n%2 && n%k && k%2 == 0) {
            f = false;
        } else {
            f = true;
        }
        cout << (f ? "YES" : "NO") << "\n";
    }
    return 0;
}