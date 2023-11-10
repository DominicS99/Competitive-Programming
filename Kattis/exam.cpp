#include <iostream>
using namespace std;

int main() {
    int k; cin >> k;
    string a, b; cin >> a >> b;
    int n = a.length();
    int z = n-k;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i] && k-- > 0) {
            res++;
        } else if (a[i] != b[i] && z-- > 0) {
            res++;
        }
    }
    cout << res << "\n";
    return 0;
}