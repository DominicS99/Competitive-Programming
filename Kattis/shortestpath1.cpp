#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(0); cin.tie(NULL);
  int n, e, q, s, u, v, w, query;

  while (1) {
    cin >> n >> e >> q >> s;
    if (!n) break;

    vector<vector<pii>> graph(n);
    while (e--) {
      cin >> u >> v >> w;
      graph[u].emplace_back(v, w);
    }

    vector<int> dist(n, 1e9);
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, s);

    while (!pq.empty()) {
      auto [w1, from] = pq.top(); 
      pq.pop();
      if (w1 > dist[from]) continue;

      for (auto &[to, w2] : graph[from]) {
        if (dist[from] + w2 >= dist[to]) continue;

        dist[to] = dist[from] + w2;
        pq.emplace(dist[to], to);
      }
      
    }

    while (q--) {
      cin >> query;
      cout << (dist[query] == 1e9 ? "Impossible" : to_string(dist[query])) << endl;
    }
    cout << endl;
  }
  
  return 0;
}
