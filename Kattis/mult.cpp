#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int n, a, fNum = -1;
    cin >> n;
    while (n--) {
        cin >> a;
        if (fNum == -1) fNum = a;
        else if (a%fNum == 0) {
            cout << a << "\n";
            fNum = -1;
        }
    }
    return 0;
}