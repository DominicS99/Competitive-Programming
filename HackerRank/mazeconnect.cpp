#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  string walls = "\\/\\/";
  vector<int> dir = {1, 0, -1, 0, 1};
  vector<int> diag = {1, 1, -1, -1, 1};

  // Input
  int m, n;
  cin >> m >> n;
  vector<string> input(m);
  for (auto &it : input) cin >> it;

  // Create a non-rotated grid
  int m2 = m+n;
  int n2 = m2;
  vector<vector<char>> grid(m2, vector<char>(n2, '.'));

  for (int j = 0; j < n; j++) {
    int i2 = j;
    int j2 = j+m-1;

    for (int i = 0; i < m; i++, i2++, j2--) {
      if (input[i][j] != '.') {
        grid[i2][j2] = '#';
        for (int d = 0; d < 4; d++) {
          if (input[i][j] != walls[d]) continue;
          int r = i + diag[d];
          int c = j + diag[d+1];

          if (r < 0 || c < 0 || r >= m || c >= n) continue;
          if (input[i][j] != input[r][c]) continue;

          r = dir[d];
          c = dir[d+1];
          grid[i2 + r][j2 + c] = '#';
        }
      }
    }
  }

  // BFS Flood fill to find enclosed areas
  int res = 0;
  queue<pii> q;
  for (int x = 0; x < m2; x++) {
    for (int y = 0; y < n2; y++) {
      if (grid[x][y] == '#') continue;
      
      bool f = true;
      grid[x][y] = '#';
      q.emplace(x, y);
      
      while (!q.empty()) {
        pii curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
          int r = curr.first + dir[i];
          int c = curr.second + dir[i+1];

          if (r < 0 || c < 0 || r >= m2 || c >= n2) {
            f = false;
            continue;
          }
          if (grid[r][c] == '#') continue;

          grid[r][c] = '#';
          q.emplace(r, c);
        }
      }

      if (f) res++;
    }
  }

  cout << res << endl;
  
  return 0;
}
