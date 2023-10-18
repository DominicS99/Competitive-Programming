#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

typedef pair<long long, int> pii;

int main() {
    priority_queue<pii> atk, def, hp;
    int n, k; cin >> n >> k;
    long long a,b,c;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        atk.emplace(a, i);
        def.emplace(b, i);
        hp.emplace(c, i);
    }

    unordered_set<int> res;
    while (k--) {
        res.insert(atk.top().second); atk.pop();
        res.insert(def.top().second); def.pop();
        res.insert(hp.top().second); hp.pop();
    }

    cout << res.size() << "\n";
    return 0;
}