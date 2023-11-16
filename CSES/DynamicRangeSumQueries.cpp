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

    void update(int i, ll diff) {
        for (i = i+1; i < n; i += (i & -i)) {
            tree[i] += diff;
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
    int n, q, x;
    cin >> n >> q;

    vector<int> d(n);
    BIT tree(n);
    for (int i = 0; i < n; i++) {
        cin >> x;
        d[i] = x;
        tree.update(i, x);
    }

    int op, a, b;
    while (q--) {
        cin >> op >> a >> b;
        if (op == 1) {
            a--;
            tree.update(a, b-d[a]);
            d[a] = b;
        } else {
            a--, b--;
            cout << tree.rQuery(a, b) << "\n";
        }
    }
    return 0;
}