#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int main() {
    int n, m; cin >> n >> m;
    queue<pii> q;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        q.emplace(x, i);
    }

    vector<int> res(m, 0);
    while (!q.empty() && n--) {
        auto [count, i] = q.front(); q.pop();
        res[i]++;
        if (--count > 0) q.emplace(count, i);
    }
    for (auto &x : res) cout << x << "\n";
    return 0;
}