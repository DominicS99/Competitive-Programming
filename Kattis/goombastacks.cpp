#include <iostream>
using namespace std;

int main() {
    int n, a, b; cin >> n;
    int res = 0;
    bool f = true;
    while (n--) {
        cin >> a >> b;
        res += a;
        if (res >= b) continue;

        f = false;
        break;
    }

    cout << (f ? "possible" : "impossible") << "\n";
    return 0;
}