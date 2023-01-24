/*
  Idea: DFS through all possible moves, used backtracking to not repeat jumps.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  
  int t, n = 10;
  vector<int> diag = {1, 1, -1, -1, 1};
  cin >> t;
  while (t--) {
    vector<string> g(n);
    int res = 0;
    for (auto & it : g) cin >> it;

    function<int(int, int)> dfs = [&](int x, int y) {
      int count = 0;
      for (int i = 0; i < 4; i++) {
        int r = x + diag[i];
        int c = y + diag[i+1];
        int r2 = r + diag[i];
        int c2 = c + diag[i+1];

        if (r2 < 0 || c2 < 0 || r2 >= n || c2 >= n) {
          continue;
        }
        
        if (g[r2][c2] == '#' && g[r][c] == 'B') {
          g[r][c] = 'V';
          count = max(count, dfs(r2,c2) + 1);
          g[r][c] = 'B';
        }
      }
      return count;
    };
    
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (g[i][j] == 'W') {
          g[i][j] = '#';
          res = max(res, dfs(i,j));
          g[i][j] = 'W';
        }
      }
    }

    cout << res << endl;
  }

  return 0;
}
