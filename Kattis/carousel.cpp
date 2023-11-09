#include <iostream>
using namespace std;

int main() {
    int n, m, a, b;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        int resA = -1, resB = -1;
        double best = 1e9;
        while (n--) {
            cin >> a >> b;
            if (a > m) continue;
            double curr = (double)b/a;
            if (curr < best || (curr == best && resA < a)) {
                best = curr;
                resA = a, resB = b;
            }
        }

        if (resA == -1) {
            cout << "No suitable tickets offered\n";
        } else {
            cout << "Buy " << resA << " tickets for $" << resB << "\n";
        }
    }
    return 0;
}