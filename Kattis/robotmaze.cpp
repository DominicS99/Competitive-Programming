// Nowhere near efficient, but this was during contest practice. AC'd it with 0.3 seconds to spare :)

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(0); cin.tie(NULL);
  vector<int> dir = {1, 0, -1, 0, 1}; // DLUR
  int t, m, n;
  string s;
  cin >> t;
  while (t--) {
    cin.ignore();
    getline(cin, s);
    cin >> m >> n;

    pii start, dest;
    
    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> grid[i][j];
        if (grid[i][j] == 'R') start = {i, j};
        if (grid[i][j] == 'D') dest = {i, j};
      }
    }

    int memo[m+1][n+1][5][3];
    memset(memo, -1, sizeof(memo));
    vector<vector<int>> dist(m, vector<int>(n, 1e9)); dist[start.first][start.second] = 0;
    priority_queue<tuple<int, pii, int, int>, vector<tuple<int, pii, int, int>>, greater<tuple<int, pii, int, int>>> pq; pq.push({0, start, 4, 0});

    bool found = false;

    while (!pq.empty()) {
      auto [d, xy, prevDir, prevSteps] = pq.top(); pq.pop();
      auto [x, y] = xy;
      if (memo[x][y][prevDir][prevSteps] != -1) continue;
      memo[x][y][prevDir][prevSteps] = d;
      
      int prevX, prevY;
      if (prevDir == 0) {
        prevX = x-1, prevY = y;
      } else if (prevDir == 1) {
        prevX = x, prevY = y+1;
      } else if (prevDir == 2) {
        prevX = x+1, prevY = y;
      } else if (prevDir == 3) {
        prevX = x, prevY = y-1;
      } else {
        prevX = -1, prevY = -1;
      }
      
      for (int i = 0; i < 4; i++) { // DLUR
        if (i == prevDir && prevSteps == 2) continue;

        int r = x + dir[i];
        int c = y + dir[i+1];
        if (r < 0 || c < 0 || r >= m || c >= n) continue;

        // cout << prevX << " " << prevY << " | " << x << " " << y << " | " << r << " " << c << "\n";
        
        if (prevX == r && prevY == c) {
          // cout << "just visited\n\n";
          continue;
        }
        if (grid[r][c] == 'B') {
          // cout << "Block here\n\n";
          continue;  
        }

        dist[r][c] = d+1;
        // cout << r << " " << c << ": " << dist[r][c] << "\n\n";
        if (r == dest.first && c == dest.second) {
          found = true;
          break;
        }

        pq.push({d+1, {r, c}, i, (prevDir == i ? 2 : 1)});
      }

      if (found) break;
    }

    cout << (dist[dest.first][dest.second] == 1e9 ? -1 : dist[dest.first][dest.second]) << endl;
  }
  return 0;
}