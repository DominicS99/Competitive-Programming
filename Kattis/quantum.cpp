#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

typedef pair<string, int> psi;
typedef pair<int, string> pis;

string apply(string s, string sop, int n) {
    for (int i = 0; i < n; i++) {
        if (sop[i] == 'N') continue;
        if (sop[i] == 'F') {
            s[i] = (s[i] == '1' ? '0' : '1');
        } else if (sop[i] == 'S') {
            s[i] = '1';
        } else {
            s[i] = '0';
        }
    }
    return s;
}

int solve(vector<psi> &quant) {
    string curr, end; cin >> curr >> end;
    priority_queue<pis, vector<pis>, greater<pis>> pq;
    pq.emplace(0, curr);
    unordered_map<string, int> vis;
    vis[curr] = 0;
    while (!pq.empty()) {
        auto [c, s] = pq.top(); pq.pop();
        if (s == end) return c;
        if (c != vis[s]) continue;
        for (auto &[sop, cost] : quant) {
            string next = apply(s, sop, s.length());
            if (vis.count(next)) {
                if (vis[next] <= vis[s]+cost) continue;
            }
            vis[next] = vis[s]+cost;
            pq.emplace(vis[next], next);
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int _t; cin >> _t;
    while (_t--) {
        int n, a, b; cin >> n >> a >> b;
        vector<psi> quant(a);
        for (auto &[x, y] : quant) cin >> x >> y;
        while (b--) {
            int res = solve(quant);
            if (res == -1) {
                cout << "NP ";
            } else {
                cout << res << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}