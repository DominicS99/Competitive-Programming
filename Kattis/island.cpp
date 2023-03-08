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

  string s;
  int mapNum = 1;
  while (getline(cin, s)) {
    // Grab next map
    int iCount = 0, bCount = 0, gCount = 0;
    vector<string> grid;
    grid.push_back(s);
    while (getline(cin, s)) {
      if (s.empty()) break;
      grid.push_back(s);
    }

    int m = grid.size();
    int n = grid[0].size();
    queue<pii> islands;

    // BFS to find all islands
    function <void (int, int) > bfs = [&] (int x, int y) {
      if (grid[x][y] == '.') return;
      
      iCount++;
      queue<pii> bridges;
      if (grid[x][y] == 'X') bridges.emplace(x, y);

      // Flood Fill current island
      queue<pii> q;
      q.emplace(x, y);
      grid[x][y] = '.';
      while (!q.empty()) {
        pii curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
          int r = curr.first + dir[i];
          int c = curr.second + dir[i+1];

          if (r < 0 || c < 0 || r >= m || c >= n) continue;
          if (grid[r][c] == '.' || grid[r][c] == 'B') continue;
          if (grid[r][c] == 'X') bridges.emplace(r, c);
          
          q.emplace(r, c);
          grid[r][c] = '.';
        }
      }

      // Find new islands based off bridges, flood bridges
      while (!bridges.empty()) {
        pii curr = bridges.front();
        bridges.pop();
        for (int i = 0; i < 4; i++) {
          bool f = false;
          int r = curr.first + dir[i];
          int c = curr.second + dir[i+1];

          if (r < 0 || c < 0 || r >= m || c >= n) continue;
          if (grid[r][c] != 'B') continue;

          bCount++;
          while (grid[r][c] == 'B') {
            grid[r][c] = '.';
            r += dir[i];
            c += dir[i+1];
          }
          
          islands.emplace(r, c);
        }
      }
    };

    // Call BFS for every unchecked island
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '.' || grid[i][j] == 'B') continue;
        gCount++;
        islands.emplace(i, j);
        while (!islands.empty()) {
          pii curr = islands.front();
          islands.pop();
          bfs(curr.first, curr.second);
        }
      }
    }

    // Print results at the end of each map case
    cout << "Map " << mapNum++ << endl;
    cout << "islands: " << iCount << endl;
    cout << "bridges: " << bCount << endl;
    cout << "buses needed: " << gCount << "\n\n";
  }

  return 0;
}
