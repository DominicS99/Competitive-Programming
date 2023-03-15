#include <bits/stdc++.h>
using namespace std;

template <class T> ostream& operator<<(ostream& os, const vector<T>& v) {
  bool isFirst = 1;
  for (auto &it : v) {
    if (!isFirst) os << endl;
    os << it;
    isFirst = 0;
  }
  return os;
};

int main() {
  ios::sync_with_stdio(0); cin.tie(NULL);

  int n, m, u, v;
  cin >> n >> m;
  n++;
  
  vector<int> res, deg(n, 0);
  vector<vector<int>> al(n);
  while (m--) {
    cin >> u >> v;
    if (u == v) continue;
    
    al[u].push_back(v);
    deg[v]++;
  }

  queue<int> q;
  for (int i = 1; i < n; i++) {
    if (deg[i]) continue;
    
    q.push(i);
    res.push_back(i);
  }

  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    for (int next : al[curr]) {
      deg[next]--;
      if (deg[next] == 0) {
        q.push(next);
        res.push_back(next);
      }
    }
  }

  if (res.size()+1 == n) {
    cout << res << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
