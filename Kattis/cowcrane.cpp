#include <iostream>
#include <vector>
using namespace std;

bool solve(vector<int> &f, vector<int> &s) {
    int t = abs(f[0]) + abs(f[0]-f[1]);
    if (t > f[2]) return false;

    t += abs(f[1]-s[0]) + abs(s[0]-s[1]);
    if (t > s[2]) return false;
    return true;
}

bool moveWith(vector<int> f, vector<int> s) {
    if (f[1] < 0 && s[0] > 0) return false;
    if (f[1] > 0 && s[0] < 0) return false;
    f[0] = (s[0] < 0 ? max(f[1], s[0]) : min(f[1], s[0]));
    return solve(s, f);
}

int main() {
    vector<int> a(3), b(3);
    for (int i = 0; i < 3; i++) {
        cin >> a[i] >> b[i];
    }

    if (abs(a[0]) > abs(b[0])) swap(a, b);
    if (moveWith(a, b)) {
        cout << "possible\n";
        return 0;
    }
    cout << (solve(a, b) || solve(b, a) ? "possible\n" : "impossible\n");
    return 0;
}