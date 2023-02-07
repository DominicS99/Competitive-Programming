/*
  Idea: Conduct DFS over all equivalent tiles. 
  
  If you never find an adjacent tile that is a lower height after completing the DFS,
    add the tile count to the result.
  
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> dir = {1, 0, -1, 0, 1};
  int n, m;
  cin >> m >> n;
  vector<vector<int>> grid(n, vector<int>(m));
  vector<vector<int>> visited(n, vector<int>(m, -1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }

  int count = 0;
  bool f = true;
  function <void (int, int)> dfs = [&] (int x, int y) {
    count++;
    visited[x][y] = grid[x][y];
    
    for (int i = 0; i < 4; i++) {
      int r = x + dir[i];
      int c = y + dir[i+1];

      if (r < 0 || c < 0 || r >= n || c >= m) continue;
      if (grid[r][c] < grid[x][y]) f = false;
      
      if (visited[r][c] == grid[x][y]) continue;
      if (grid[r][c] != grid[x][y]) continue;

      dfs(r, c);
    }
  };

  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (visited[i][j] == -1) {
        f = true;
        count = 0;
        dfs(i, j);
        if (!f) continue;
        res += count;
      }
    }
  }

  cout << res << endl;
  return 0;
}
