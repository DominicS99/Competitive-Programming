/*
  Struggled to understand this problem from other perspectives, so I went back to what I understood and managed to solve it.
  My idea was to conduct a BFS, but used a minimum priority queue instead because I needed the lowest levels to start first.
  This way, I could continue traversing on the lowest levels until I reached the top left corner (start). 
  
  Logic example:
  5
  0  1  2  4  11
  11 11 11 5  11
  11 11 7  6  11
  11 11 8  11 11
  11 11 9  10 3
  
  We always start at the bottom right corner, so add the 3 to the min PQ.
  Conduct BFS at 3 -> add max(3,10) and max(3,11) to the min PQ. minPQ is now 10, 11.
  The front of the min PQ is the 10, so we conduct BFS at 10 -> add max(10,9) and max(10,11) to the min PQ. minPQ is now 10, 11, 11.
  The front of the min PQ is the 10, so we conduct BFS at 10 (originally 9) -> add max(10,8) and max(10,11) to the min PQ. minPQ is now 10, 11, 11, 11.
  The front of the min PQ is the 10, so we conduct BFS at 10 (originally 8) -> add max(10,7) and max(10,11) to the min PQ. minPQ is now 10, 11, 11, 11, 11.
  Continuing this eventually leads to the top left corner, and we never had to go higher than 10 to get there, so we print this number.
*/

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
  vi dir = {0, 1, 0, -1, 0};
  int n;
  cin >> n;
  vector<vi> g(n, vi(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> g[i][j];
    }
  }

  int x = n-1, y = n-1;
  priority_queue<vi> minPQ;
  minPQ.push({-1 * g[x][y], x, y});
  g[x][y] = -1;

  while (!minPQ.empty()) {
    vi curr = minPQ.top();
    curr[0] *= -1;
    minPQ.pop();
    for (int i = 0; i < 4; i++) {
      int r = curr[1] + dir[i];
      int c = curr[2] + dir[i+1];

      if (r < 0 || c < 0 || r >= n || c >= n) continue;
      if (g[r][c] == -1) continue;
      if (r == 0 && c == 0) {
        cout << curr[0] << endl;
        return 0;
      }
      int high = max(g[r][c], curr[0]);
      minPQ.push({-1 * high, r, c});
      g[r][c] = -1;
    }
  }
  
  return 0;
}
