#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(0); cin.tie(NULL);
  int n, m, q, s, e1, e2, e3, e4, e5, dest;
  while (1) {
    cin>>n>>m>>q>>s;
    if (!n && !m && !q && !s) break;
    vector<vector<vector<int>>> al(n);
    while (m--) {
      cin>>e1>>e2>>e3>>e4>>e5;
      al[e1].push_back({e2,e3,e4,e5});
    }

    vector<int> dist(n, 1e9); dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq; pq.emplace(0, s);

    while (!pq.empty()) {
      auto [d, u] = pq.top(); pq.pop();
      if (d > dist[u]) continue;
      for (auto &e : al[u]) {
        int &v = e[0],&ts = e[1],&P = e[2],&w = e[3];
        if (!P && dist[u] > ts) continue;
        int nxt = (dist[u]>ts ? ts + ceil((dist[u]-ts)/(double)P) * P : ts) - dist[u];
        if (dist[u]+nxt+w >= dist[v]) continue;
        dist[v] = dist[u]+nxt+w;
        pq.emplace(dist[v], v);
      }
    }

    while (q--) {
      cin>>dest;
      if (dist[dest] == 1e9) cout << "Impossible" << endl;
      else cout << dist[dest] << endl;
    }
  }
  return 0;
}