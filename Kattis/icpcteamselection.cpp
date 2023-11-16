#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int _t; cin >> _t;
    while (_t--) {
        int n; cin >> n;
        vector<int> d(n*3); for (auto &x : d) cin >> x;
        sort(d.begin(), d.end());

        int res = 0;
        int l = 0, r = d.size()-1;
        while (l < r) {
            l++; r--;
            res += d[r--];
        }
        cout << res << "\n";
    }
    return 0;
}