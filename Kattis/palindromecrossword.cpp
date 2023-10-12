/*
Whew.

Basically you can find the best palindrome length from a particular spot by expanding outwards from a spot in the middle.
Use DP to cache this information, since a lot of it will repeat.

Now that you know the best length, just backtrace from the best coords to find the path.
*/

#include <bits/stdc++.h>
using namespace std;

const int LIM = 100;

int memo[LIM][LIM][LIM][LIM];

int main() {
  vector<int> dir = {0, 1, 0, -1, 0}; //RDLU
  ios::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (auto &it : grid) cin >> it;

    memset(memo, -1, sizeof(memo));

    // Recursive palindrome finding with DP
    function<int(int, int, int, int)> solve = [&] (int x, int y, int a, int b) {
      auto &res = memo[x][y][a][b];
      if (res != -1) return res;

      res = 0;
      for (int i = 2; i < 4; i++) {
        int x2 = x + dir[i];
        int y2 = y + dir[i+1];

        if (x2 < 0 || y2 < 0) continue;
        
        for (int j = 0; j < 2; j++) {
          int a2 = a + dir[j];
          int b2 = b + dir[j+1];

          if (a2 >= n || b2 >= n) continue;
          if (grid[x2][y2] != grid[a2][b2]) continue;

          auto curr = solve(x2, y2, a2, b2);
          res = max(res, curr+2);
        }
      }

      return res;
    };

    // Find longest palindrome and keep path string
    int tempX, tempY, tempA, tempB;
    int bestLen = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        auto firstCurr = solve(i, j, i, j);
        if (bestLen < firstCurr+1) {
          bestLen = firstCurr+1;
          tempX = i, tempY = j;
          tempA = i, tempB = j;
        }

        if (i+1 < n && grid[i][j] == grid[i+1][j]) {
          auto curr = solve(i, j, i+1, j);
          if (bestLen < curr+2) {
            bestLen = curr+2;
            tempX = i, tempY = j;
            tempA = i+1, tempB = j;
          }
        }

        if (j+1 < n && grid[i][j] == grid[i][j+1]) {
          auto curr = solve(i, j, i, j+1);
          if (bestLen < curr+2) {
            bestLen = curr+2;
            tempX = i, tempY = j;
            tempA = i, tempB = j+1;
          }
        }
      }
    }

    // Find Path
    string path = "", word; word = grid[tempX][tempY];
    if (bestLen%2 == 0) {
      word += grid[tempA][tempB];
      if (tempX+1 == tempA) path = "D";
      else path = "R";
    }
    
    while (memo[tempX][tempY][tempA][tempB] > 0) {
      for (int i = 2; i < 4; i++) {
        int x2 = tempX + dir[i];
        int y2 = tempY + dir[i+1];

        if (x2 < 0 || y2 < 0) continue;
        
        for (int j = 0; j < 2; j++) {
          int a2 = tempA + dir[j];
          int b2 = tempB + dir[j+1];

          if (a2 >= n || b2 >= n) continue;

          if (memo[x2][y2][a2][b2] + 2 == memo[tempX][tempY][tempA][tempB]) {
            path = (i%2 ? 'D' : 'R') + path + (j%2 ? 'D' : 'R');
            word = grid[x2][y2] + word + grid[a2][b2];
            tempX = x2, tempY = y2;
            tempA = a2, tempB = b2;
            break;
          }
        }
      }
    }

    cout << word << " " << tempX+1 << " " << tempY+1 << " " << path << "S" << "\n";
  }
  return 0;
}