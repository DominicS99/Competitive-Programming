#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int w, n; cin >> w >> n;
    vector<int> d;
    d.push_back(0);
    while (n--) {
        int x; cin >> x;
        d.push_back(x);
    }
    d.push_back(w);
    n = d.size();
    
    set<int> s;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            s.insert(d[j]-d[i]);
        }
    }

    for (auto &x : s) cout << x << " ";
    cout << "\n";
    return 0;
}