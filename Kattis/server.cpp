#include <iostream>
using namespace std;

int main() {
    int n, t; cin >> n >> t;
    int x, res = 0;
    while (n--) {
        cin >> x;
        t -= x;
        if (t >= 0) res++;
    }
    cout << res << "\n";
    return 0;
}