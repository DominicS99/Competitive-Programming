/*
  Idea: Group everything within the grid, then run queries in O(1) time!
*/

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  vector<int> dir = {1, 0, -1, 0, 1};
  int m, n, q;
  cin >> m >> n;
  vector<string> input(m);
  for (auto &it : input) cin >> it;

  int group = 1;
  vector<vector<int>> grid(m, vector<int>(n, 0));

  function <void (int, int)> bfs = [&] (int x, int y) {
    queue<pii> q;
    q.emplace(x, y);
    while (!q.empty()) {
      pii curr = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        int r = curr.first + dir[i];
        int c = curr.second + dir[i+1];

        if (r < 0 || c < 0 || r >= m || c >= n) continue;
        if (input[r][c] != input[curr.first][curr.second]) continue;
        if (grid[r][c] > 0) continue;

        grid[r][c] = group;
        q.emplace(r, c);
      }
    }
  };
  
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] > 0) continue;
      grid[i][j] = group;
      bfs(i, j);
      group++;
    }
  }


  int fx, fy, sx, sy;
  cin >> q;
  while (q--) {
    cin >> fx >> fy >> sx >> sy;
    if (grid[fx-1][fy-1] == grid[sx-1][sy-1]) {
      cout << (input[fx-1][fy-1] == '0' ? "binary" : "decimal") << endl;
    } else {
      cout << "neither" << endl;
    }
  }

  return 0;
}
