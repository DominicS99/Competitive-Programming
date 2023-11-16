#include <bits/stdc++.h>
using namespace std;

int main() {
    double t; cin >> t;
    int n, x; cin >> n;

    int res = 0;
    double low = 1e9;
    priority_queue<tuple<double, double, int>> pq;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (low > x) low = x;
        pq.emplace(x, x, 1);
    }

    while (1) {
        auto [curr, init, cuts] = pq.top(); pq.pop();
        if (low / curr >= t) break;
        
        res++;
        curr = init / ++cuts;
        low = min(low, curr);
        pq.emplace(curr, init, cuts);
    }

    cout << res << "\n";
    return 0;
}