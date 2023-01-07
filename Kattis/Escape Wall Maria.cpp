#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

// 0 = safe
// 1 = burned (doesn't move)
// s = start
// U/D/L/R = directions that can be entered from

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  int t, n, m;
  cin >> t >> n >> m;

  vector<string> g(n);
  for (auto &it : g) cin >> it;

  vector<int> dir = {0, 1, 0, -1, 0};
  queue<pii> q;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == 'S') {
        q.push({i, j});
        g[i][j] = '1';
      }
    }
  }

  bool exit = false;
  int count = 0;
  while (!q.empty()) {
    queue<pii> newQ;
    while (!q.empty()) {
      pii curr = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        int r = dir[i] + curr.first;
        int c = dir[i + 1] + curr.second;

        if (r < 0 || c < 0 || r >= n || c >= m) {
          exit = true;
          break;
        }
        if (g[r][c] == '1') continue;
        if ((i == 1 && g[r][c] == 'U') || (i == 0 && g[r][c] == 'L') ||
            (i == 3 && g[r][c] == 'D') || (i == 2 && g[r][c] == 'R') ||
            g[r][c] == '0') {
          newQ.push({r, c});
          g[r][c] = '1';
        }
      }
    }

    if (exit) break;
    count++;
    q = newQ;
  }

  if (exit && count <= t) {
    cout << count << endl;
  } else {
    cout << "NOT POSSIBLE" << endl;
  }

  return 0;
}
