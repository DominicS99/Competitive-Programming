#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(0); cin.tie(NULL);
  vector<int> dir = {1, 0, -1, 0, 1};
  int m, n;
  char in;
  cin >> m >> n;
  vector<vector<int>> grid(m, vector<int>(n));
  for (int i = 0; i < n; i++) cin >> in;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }
  for (int i = 0; i < n; i++) cin >> in;

  vector<vector<int>> dist(m, vector<int>(n, 1e9)), in_queue(m, vector<int>(n, 0));
  vector<pii> ends(n);
  set<pii> test;
  queue<pii> q;
  for (int i = 0; i < n; i++) {
    if (grid[m-1][i] < 0) {
      cout << 0 << endl;
      return 0;
    }
    dist[m-1][i] = grid[m-1][i];
    q.emplace(m-1, i);
    in_queue[m-1][i] = 1;
  }

  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop(); in_queue[x][y] = 0;
    bool f = false;
    if (grid[x][y] < 0) {
      for (int i = 0; i < 4; i++) {
        int r = x + dir[i];
        int c = y + dir[i+1];
        if (r < 0 || c < 0 || r >= m || c >= n) continue;
        if (grid[r][c] + grid[x][y] < 0) f = true;
      }
    }

    if (f) {
      ends.emplace_back(x, y);
      test.insert({x, y});
      continue;
    }
    
    for (int i = 0; i < 4; i++) {
      int r = x + dir[i];
      int c = y + dir[i+1];
      if (r < 0 || c < 0 || r >= m || c >= n) continue;
      if (dist[x][y]+grid[r][c] >= dist[r][c]) continue;
      dist[r][c] = dist[x][y] + grid[r][c];
      if (in_queue[r][c]) continue;

      q.emplace(r, c);
      in_queue[r][c] = 1;
    }
  }

  int res = 1e9;
  for (int i = 0; i < n; i++) {
    if (test.count({0, i})) continue;
    res = min(res, dist[0][i]);
  }
  for (auto &[x, y] : ends) {
    for (int i = 0; i < 4; i++) {
      int r = x + dir[i];
      int c = y + dir[i+1];
      if (r < 0 || c < 0 || r >= m || c >= n) continue;
      if (test.count({r, c})) continue;
      res = min(res, dist[r][c]);
    }
  }

  cout << res << endl;
  return 0;
}