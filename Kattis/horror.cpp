#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(NULL);
  
  int n, h, l, u, v;
  cin >> n >> h >> l;
  
  vector<int> starts(h);
  for (auto &it : starts) cin >> it;

  vector<vector<int>> al(n);
  while (l--) {
    cin >> u >> v;
    al[u].push_back(v);
    al[v].push_back(u);
  }

  vector<int> res(n, 1e9);
  for (int it : starts) {
    queue<int> q; 
    q.push(it);
    
    int count = 0; 
    res[it] = count;
    
    while (!q.empty()) {
      count++;
      queue<int> newQ;

      while (!q.empty()) {
        int i = q.front(); q.pop();
        for (int j : al[i]) {
          if (res[j] <= count) continue;
          res[j] = count;
          newQ.push(j);
        }
      }
      swap(q, newQ);
    }
  }

  cout << max_element(res.begin(), res.end()) - res.begin() << endl;
  return 0;
}
