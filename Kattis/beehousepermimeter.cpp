/*
  There are 3 parts to this problem: 
    Create a 2D array that can work with the honeycomb grid style.
    Flood fill everything outside the house.
    Count walls that touch outside.
    
   Very interesting problem. If something isn't working, make your own tests!
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int main() {
  // Input + Create Honeycomb grid
  vector<int> dir = {1, 0, -1, -1, 0, 1, 1};
  int R, k;
  cin >> R >> k;
  int n = 2 * R - 1;
  vector<vector<int>> grid(n+2, vector<int>(n+2, -1));
  int curr = 1, start = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = start; j <= R; j++) {
      grid[i][j] = curr;
      curr++;
    }
    i < (n/2)+1 ? R++ : start++;
  }

  unordered_set<int> house;
  for (int i = 0; i < k; i++) {
    int temp;
    cin >> temp;
    house.insert(temp);
  }

  // BFS Flood Fill
  queue<pii> q;
  grid[0][0] = -2;
  q.emplace(0, 0);
  while (!q.empty()) {
    pii curr = q.front();
    q.pop();
    for (int i = 0; i < 6; i++) {
      int r = curr.first + dir[i];
      int c = curr.second + dir[i+1];
      if (r < 0 || c < 0 || r > n+1 || c > n+1) continue;
      if (house.count(grid[r][c])) continue;
      if (grid[r][c] == -2) continue;
      
      grid[r][c] = -2;
      q.emplace(r, c);
    }
  }

  // Count walls
  ll res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (house.count(grid[i][j])) {
        for (int k = 0; k < 6; k++) {
          int r = i + dir[k];
          int c = j + dir[k+1];

          if (grid[r][c] == -2) res++;
        }
      }
    }
  }

  cout << res << endl;

  return 0;
}
