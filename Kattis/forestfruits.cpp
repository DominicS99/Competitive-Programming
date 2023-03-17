/*
  Idea: SSSP -> Dijkstra. Then greedily find the minimal necessary path to take (doubled).
  I finally feel like I'm learning!
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef pair<LL, LL> pll;

int main() {
  ios::sync_with_stdio(0); cin.tie(NULL);
  int n, e, c, k, m, u, v, w;
  cin >> n >> e >> c >> k >> m;
  n++;
  
  // Fill Adj list
  vector<vector<pll>> al(n);
  while (e--) {
    cin >> u >> v >> w;
    al[u].emplace_back(v, w);
    al[v].emplace_back(u, w);
  }

  // Maintaining clear information for later
  vector<int> dest(c);
  for (auto &it : dest) cin >> it;

  // Dijkstra SSSP
  vector<LL> dist(n, LLONG_MAX);
  dist[1] = 0;
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  pq.emplace(0, 1);

  while (!pq.empty()) {
    auto [d, i] = pq.top(); pq.pop();
    if (d != dist[i]) continue;

    for (auto [j, w] : al[i]) {
      if (dist[j] <= dist[i]+w) continue;
      dist[j] = dist[i] + w;
      pq.emplace(dist[j], j);
    }
  }

  // Store all distances to clearings in PQ
  priority_queue<LL, vector<LL>, greater<LL>> res;
  for (auto num : dest) {
    if (dist[num] == LLONG_MAX) continue;
    res.push(dist[num]);
  }

  // Remove from PQ until the fruit starts resetting, the # of days finishes, 
  // or all the clearings get emptied too early.
  int fin = min(m, k);
  while (fin-- > 1) {
    if (res.empty()) break;
    res.pop();
  }

  cout << (res.empty() ? -1 : res.top()*2) << endl;
  return 0;
}
