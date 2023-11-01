#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int n, x, curr; 
    cin >> n >> curr;
    int res = curr-1;
    while (--n) {
        cin >> x;
        if (curr == x) continue;

        curr = x;
        res--;
    }
    cout << res << "\n";
    return 0;
}