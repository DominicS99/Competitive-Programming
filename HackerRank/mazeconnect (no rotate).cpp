#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
typedef long long int ll;

int main() {
  vector<int> dir = {1, 1, -1, -1, 1, 0, -1, 0, 1};
  int m, n;
  cin >> m >> n;
  vector<vector<char>> grid(m + 2, vector<char>(n + 2, 'E'));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> grid[i][j];
    }
  }

  bool f;

  function<void(int, int)> bfs = [&](int x, int y) {
    queue<pii> q;
    q.emplace(x, y);
    grid[x][y] = '#';
    while (!q.empty()) {
      pii curr = q.front();
      q.pop();

      for (int i = 0; i < 8; i++) {
        int r = curr.first + dir[i];
        int c = curr.second + dir[i + 1];

        if (i == 0 && grid[r - 1][c] == '/') continue;
        if (i == 1 && grid[r][c + 1] == '\\') continue;
        if (i == 2 && grid[r][c + 1] == '/') continue;
        if (i == 3 && grid[r + 1][c] == '\\') continue;
        if (grid[r][c] == 'E') f = false;
        if (grid[r][c] != '.') continue;

        grid[r][c] = '#';
        q.emplace(r, c);
      }
    }
  };

  ll res = 0;
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      if (grid[i][j] == '/' && grid[i + 1][j] == '\\' &&
          grid[i][j + 1] == '\\' && grid[i + 1][j + 1] == '/') {
        res++;
      } else if (grid[i][j] == '.') {
        f = true;
        bfs(i, j);
        if (f) res++;
      }
    }
  }

  cout << res << endl;
  return 0;
}
