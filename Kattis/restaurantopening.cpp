#include <iostream>
#include <vector>
#include <functional>
using namespace std;

typedef long long int ll;

int main() {
  int m, n;
  cin >> m >> n;
  vector<vector<int>> grid(m, vector<int>(n));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  function <ll (int, int)> solve = [&] (int x, int y) {
    ll curr = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        curr += grid[i][j] * (abs(i-x) + abs(j-y));
      }
    }
    return curr;
  };

  ll res = 1e9;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      res = min(res, solve(i, j));
    }
  }

  cout << res << endl;
  
  return 0;
}
