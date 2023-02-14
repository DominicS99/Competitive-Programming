/*
  Idea: BFS grid traversal. 
  - Need to keep track of Player and Fire separately.
  - Keep track of turns passed.
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
  vector<int> dir = {1, 0, -1, 0, 1};
  int m, n;
  cin >> m >> n;
  vector<string> grid(m);
  for (auto &it : grid) cin >> it;

  queue<pii> q, fq;
  int res = 0;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 'J') q.emplace(i, j);
      if (grid[i][j] == 'F') fq.emplace(i, j);
    }
  }

  function <bool (queue<pii>&, bool)> bfs = [&] (queue<pii> &currQ, bool fire) {
    queue<pii> newQ;
    while (!currQ.empty()) {
      pii curr = currQ.front();
      currQ.pop();
  
      for (int i = 0; i < 4; i++) {
        int r = curr.first + dir[i];
        int c = curr.second + dir[i+1];
    
        if (r < 0 || c < 0 || r >= m || c >= n) {
          if (fire) continue;
          return true;
        }
        if (grid[r][c] != '.') continue;
        grid[r][c] = '#';
        newQ.emplace(r, c);
      }
    }
    currQ = newQ;
    return false;
  };

  bool win = false;
  while (!q.empty()) {
    res++;
    bfs(fq, true);
    if (bfs(q, false)) {
      win = true;
      break;
    }
  }

  if (win) {
    cout << res << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }

  return 0;
}
