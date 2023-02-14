/*
  Idea: DFS Flood fill, count land sides touched.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> dir = {1, 0, -1, 0, 1};
  int m, n;
  cin >> m >> n;
  vector<vector<char>> grid(m+2, vector<char>(n+2, '0'));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> grid[i][j];
    }
  }

  int res = 0;
  function <void (int, int)> dfs = [&] (int x, int y) {
    grid[x][y] = '2';
    for (int i = 0; i < 4; i++) {
      int r = x + dir[i];
      int c = y + dir[i+1];

      if (r < 0 || c < 0 || r > m+1 || c > n+1) continue;
      if (grid[r][c] == '2') continue;
      if (grid[r][c] == '1') {
        res++;
        continue;
      }

      dfs(r,c);
    }
  };
  
  dfs(0, 0);

  cout << res << endl;

  return 0;
}
