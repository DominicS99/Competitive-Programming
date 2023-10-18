#include <iostream>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int x;
    while (n--) {
        cin >> x;
        while (k > 0 && x%2 == 0) {
            k--;
            x /= 2;
        }
    }
    cout << (k == 0) << "\n";
    return 0;
}