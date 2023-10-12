#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int m, n, q;
    cin >> m >> n;
    vector<int> d(m);
    for (auto &it : d) cin >> it;

    unordered_set<int> cSum, dnf;
    unordered_map<int, int> pSum, sSum;
    cSum.insert(0);
    int pref = 0, suff = 0;
    for (int i = 0; i < m; i++) {
        pref += d[i];
        pSum[pref] = i+1;
        suff += d[m-i-1];
        sSum[suff] = i+1;
    }

    while (n--) {
        cin >> q;
        if (q > pref || dnf.count(q)) cout << "No\n";
        else if (pSum.count(q) || sSum.count(q) || cSum.count(q)) cout << "Yes\n";
        else {
            bool f = false;
            for (auto &[val, index] : pSum) {
                if (sSum.count(q - val) && index + sSum[q-val] <= m) {
                    cSum.insert(q);
                    cout << "Yes\n";
                    f = true;
                    break;
                }
            }
            if (!f) {
                dnf.insert(q);
                cout << "No\n";
            }
        }
    }
    return 0;
}