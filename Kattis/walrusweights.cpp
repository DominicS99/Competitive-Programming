/*
  Idea: Subset Sum DP
*/

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 2000;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  vector<int> d(n);
  for (auto &it : d) cin >> it;

  vector<vector<bool>> memo(n+1, vector<bool>(MAX, 0));
  memo[0][0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= MAX; j++) {
      if (j < d[i-1]) {
        memo[i][j] = memo[i-1][j];
      } else {
        memo[i][j] = memo[i-1][j] || memo[i-1][j-d[i-1]];
      }
    }
  }

  int res = 1000;
  if (!memo[n][res]) {
    for (int i = 1; i < 1000; i++) {
      if (memo[n][res+i]) {
        res += i;
        break;
      } else if (memo[n][res-i]) {
        res -= i;
        break;
      }
    }
  }

  cout << res << endl;
  return 0;
}
