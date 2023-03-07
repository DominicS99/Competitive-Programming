/*
  Idea: Flood fill and count turns. Should've looked at this problem more during the regional...
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

int main() {
  vector<int> dir = {1, 0, -1, 0, 1};
  int m, n;
  char symbol;
  cin >> m >> n;
  
  vector<vector<char>> grid(m+2, vector<char>(n+2, '-'));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> grid[i][j];
    }
  }

  queue<pii> q;
  for (int i = 0; i < m+2; i++) {
    for (int j = 0; j < n+2; j++) {
      if (grid[i][j] == '-') q.emplace(i, j);
    }
  }

  int res = 0;
  while (true) {
    queue<pii> newQ;
    while (!q.empty()) {
      pii curr = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        int r = curr.first + dir[i];
        int c = curr.second + dir[i+1];

        if (r < 0 || c < 0 || r > m+1 || c > n+1) continue;
        if (grid[r][c] == '-') continue;

        grid[r][c] = '-';
        newQ.emplace(r, c);
      }
    }

    if (newQ.empty()) break;
    q = newQ;
    res++;
  }

  cout << res << endl;
  return 0;
}
