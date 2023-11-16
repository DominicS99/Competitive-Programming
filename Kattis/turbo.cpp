#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

struct BIT {
    int n;
    vector<ll> tree;

    BIT(int size) {
        n = size+1;
        tree.resize(n);
    }

    void update(int i, ll val) {
        for (i = i+1; i < n; i += (i & -i)) {
            tree[i] += val;
        }
    }

    ll query(int i) {
        ll res = 0;
        for (i = i+1; i > 0; i -= (i & -i)) {
            res += tree[i];
        }
        return res;
    }

    ll rQuery(int l, int r) {
        return query(r) - query(l-1);
    }
};


int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int n, x; cin >> n;

    vector<int> indexes(n);
    BIT tree(n);
    for (int i = 0; i < n; i++) {
        cin >> x; x--;
        tree.update(i, 1);
        indexes[x] = i;
    }

    bool odd = 1;
    int l = 0, r = n-1;
    while (l <= r) {
        if (odd) {
            cout << tree.query(indexes[l]-1) << "\n";
            tree.update(indexes[l++], -1);
        } else {
            cout << tree.rQuery(indexes[r]+1, n-1) << "\n";
            tree.update(indexes[r--], -1);
        }
        odd = !odd;
    }
    return 0;
}