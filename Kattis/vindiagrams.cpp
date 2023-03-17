#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int main() {
  vector<int> dir = {1, 0, -1, 0, 1};
  vector<int> diag = {1, 1, -1, -1, 1};
  int m, n;
  cin >> m >> n;

  // Creating grid with surrounding buffer area
  // Also noting locations of 'A' and 'B'
  vector<pii> starts;
  vector<vector<char>> grid(m+2, vector<char>(n+2, '.'));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == '.' || grid[i][j] == 'X') continue;
      starts.emplace_back(i, j);
    }
  }

  // Fill all the X's as either A or B.
  // This was done by checking for the direction we just came from,
  // and seeing if we could continue in that direction. Otherwise,
  // we just found where the next 'X' was. Ends when both sides have
  // the same loop character (fully wrapped around).
  for (auto [a, b] : starts) {
    queue<pii> q;
    char loopChar = grid[a][b];

    for (int i = 0; i < 4; i++) {
      int r = a + dir[i];
      int c = b + dir[i+1];

      if (grid[r][c] != 'X') continue;
      grid[r][c] = loopChar;
      q.emplace(r, c);
    }

    while (!q.empty()) {
      auto [x, y] = q.front(); q.pop();

      int i;
      int tempR, tempC;
      int revR, revC;
      for (i = 0; i < 4; i++) {
        int r = x + dir[i];
        int c = y + dir[i+1];

        if (grid[r][c] == 'X') tempR = r, tempC = c;

        if (grid[r][c] == loopChar) {
          int rev = (i+2)%4;
          revR = x + dir[rev];
          revC = y + dir[rev+1];
        }
      }

      if (grid[revR][revC] == '.') {
        revR = tempR;
        revC = tempC;
      }

      if (grid[revR][revC] == loopChar) break;

      grid[revR][revC] = loopChar;
      q.emplace(revR, revC);
    }
  }

  // Flood fill the outside with '#'
  queue<pii> q;
  grid[0][0] = '#';
  q.emplace(0, 0);
  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();

    for (int i = 0; i < 4; i++) {
      int r = x + dir[i];
      int c = y + dir[i+1];

      if (r < 0 || c < 0 || r > m+1 || c > n+1) continue;
      if (grid[r][c] != '.') continue;

      grid[r][c] = '#';
      q.emplace(r, c);
    }
  }

  // Find the first intersection point
  // The intersection point is the spot where there are 4
  // useful diagonals: One is set A, one is set B, one is
  // the intersection, and one is outside. From the outside,
  // we can find the information of all the other sets.
  int sectR = -1, sectC = -1;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (grid[i][j] == '#' || grid[i][j] == '.') continue;
      bool f = true;
      for (int x = 0; x < 4; x++) {
        int r = i + dir[x];
        int c = j + dir[x+1];

        if (grid[r][c] == '#' || grid[r][c] == '.') {
          f = false;
          break;
        }
      }
      if (f) {
        sectR = i; sectC = j;
        break;
      }
    }
    if (sectR != -1) break;
  }

  // Find the '#' position that is diag from intersect point
  int flipR, flipC;
  for (int i = 0; i < 4; i++) {
    int r = sectR + diag[i];
    int c = sectC + diag[i+1];
    if (grid[r][c] != '#') continue;
    sectR = r; sectC = c;
    flipR = diag[i] * -1; flipC = diag[i+1] * -1;
    break;
  }

  // Find the direction with 'A', then emplace the groups
  // with order 'A', 'B', intersection.
  vector<pii> groups;
  if (grid[sectR + flipR][sectC] == 'A') {
    groups.emplace_back(sectR + (flipR * 2), sectC);
    groups.emplace_back(sectR, sectC + (flipC * 2));
  } else {
    groups.emplace_back(sectR, sectC + (flipC * 2));
    groups.emplace_back(sectR + (flipR * 2), sectC);
  }
  groups.emplace_back(sectR + (flipR * 2), sectC + (flipC * 2));

  // Flood fill and count for each set
  vector<int> res;
  for (auto [a, b] : groups) {
    queue<pii> q;
    grid[a][b] = '#';
    q.emplace(a, b);
    
    int count = 1;
    while (!q.empty()) {
      auto [x, y] = q.front(); q.pop();

      for (int i = 0; i < 4; i++) {
        int r = x + dir[i];
        int c = y + dir[i+1];

        if (grid[r][c] != '.') continue;

        count++;
        grid[r][c] = '#';
        q.emplace(r, c);
      }
    }

    res.push_back(count);
  }

  // Print results
  for (auto &it : res) cout << it << " ";
  cout << endl;

  return 0;
}
