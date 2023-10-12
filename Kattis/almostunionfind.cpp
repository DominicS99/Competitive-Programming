#include <bits/stdc++.h>
using namespace std;

#define LIM 100000

typedef long long ll;

class DSU {
public:
    vector<ll> parent, size, sum;

    DSU(int n) {
        parent.assign(n, 0);
        size.assign(n, 0);
        sum.assign(n, 0);
    }
    
    int findSet(int v) {
        if (v <= LIM && parent[v] == 0) {
            parent[v] = v+LIM;
            size[v+LIM] = 1;
            sum[v+LIM] = v;
        } else if (v > LIM && parent[v] == 0) {
            parent[v] = v;
            size[v] = 1;
            sum[v] = v-LIM;
        }
        if (parent[v] == v) return parent[v];
        return parent[v] = findSet(parent[v]);
    }

    void unionSet(int x, int y, int op) {
        int a = findSet(x);
        int b = findSet(y);
        if (a != b) {
            if (op == 1) {
                if (size[a] < size[b]) swap(a, b);
                parent[b] = a;
                size[a] += size[b];
                sum[a] += sum[b];
            } else {
                sum[a] -= (ll)x;
                size[a]--;

                parent[x] = b;

                sum[b] += (ll)x;
                size[b]++;
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int n, m, o, p, q, x;
    while (cin >> n) {
        DSU dsu(n+1+LIM);
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> o;
            if (o == 3) {
                cin >> x;
                x = dsu.findSet(x);
                cout << dsu.size[x] << " " << dsu.sum[x] << endl;
            } else {
                cin >> p >> q;
                dsu.unionSet(p, q, o);
            }
        }
    }
    return 0;
}