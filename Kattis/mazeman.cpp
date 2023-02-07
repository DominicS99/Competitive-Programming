#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  vector<int> dir = {1, 0, -1, 0, 1};
  int n, m;
  cin >> n >> m;
  cin.ignore();
  vector<string> grid(n);
  for (auto &it : grid) getline(cin, it);
  bool f;

  function <int (int, int)> dfs = [&] (int x, int y) {
    int count = 0;
    for (int i = 0; i < 4; i++) {
      int r = x + dir[i];
      int c = y + dir[i+1];

      if (r < 0 || c < 0 || r >= n || c >= m) continue;
      if (grid[r][c] == 'X') continue;
      if (grid[r][c] >= 'A' && grid[r][c] <= 'W') {
        f = true;
        continue;
      }
      
      if (grid[r][c] == '.') count++;
      grid[r][c] = 'X';
      count += dfs(r, c);
    }

    return count;
  };

  int res = 0, enter = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '.') {
        grid[i][j] = 'X';
        f = false;
        int count = dfs(i, j) + 1;
        if (f) {
          enter++;
        } else {
          res += count;
        }
      }
    }
  }

  cout << enter << " " << res << endl;

  return 0;
}
