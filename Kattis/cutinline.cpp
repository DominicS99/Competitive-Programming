#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s, a, b;
    int n; cin >> n;
    vector<string> d(n);
    for (auto &x : d) cin >> x;

    cin >> n;
    while (n--) {
        cin >> s;
        if (s == "cut") {
            cin >> a >> b;
            for (auto it = d.begin(); it != d.end(); it++) {
                if (*it != b) continue;

                d.insert(it, a);
                break;
            }
        } else {
            cin >> a;
            for (int i = 0; i < d.size(); i++) {
                if (d[i] != a) continue;
                
                d.erase(d.begin()+i);
                break;
            }
        }
    }

    for (auto &x : d) cout << x << "\n";
    return 0;
}