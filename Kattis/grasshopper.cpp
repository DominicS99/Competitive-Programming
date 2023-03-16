#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(0); cin.tie(NULL);
  vector<int> dirX = {-2, -1, 1, 2, 2, 1, -1, -2};
  vector<int> dirY = {1, 2, 2, 1, -1, -2, -2, -1};
  int m, n, si, sj, ei, ej;

  while (cin >> m) {
    cin >> n >> si >> sj >> ei >> ej;
    si--; sj--; ei--; ej--;

    int res = 0;
    function<bool()> bfs = [&] {
      if (si == ei && sj == ej) return true;

      vector<vector<int>> grid(m, vector<int>(n, 0));
      grid[ei][ej] = 2;
      grid[si][sj] = 1;
      
      queue<pii> q;
      q.emplace(si, sj);
      
      while (!q.empty()) {
        res++;
        queue<pii> newQ;
        
        while (!q.empty()) {
          auto [x, y] = q.front();
          q.pop();

          for (int i = 0; i < 8; i++) {
            int r = x + dirX[i];
            int c = y + dirY[i];

            if (r < 0 || c < 0 || r >= m || c >= n) continue;
            if (grid[r][c] == 2) return true;
            if (grid[r][c] == 1) continue;

            grid[r][c] = 1;
            newQ.emplace(r, c);
          }
        }
        
        swap(q, newQ);
      }
      return false;
    };

    bool f = bfs();
    cout << (f ? to_string(res) : "impossible") << endl;
  }

  return 0;
}
