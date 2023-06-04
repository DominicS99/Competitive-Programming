#include <bits/stdc++.h>
using namespace std;
 
typedef vector<vector<int>> grid;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t, n, a, b, c;
  cin >> t;
  while (t--) {
    cin >> n;
    grid g(2, vector<int>(n));
    vector<int> sum(2, 0);
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        cin >> g[i][j];
      }
    }
 
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (g[0][i] != g[1][i]) {
        count++;
        sum[0] += g[0][i];
        sum[1] += g[1][i];
      }
    }
 
    int res = abs(sum[0] - sum[1]);
    count -= res;
    if (count%2) {
      res++;
      count--;
    }
    if (count) res++;
    cout << res << endl;
  }
 
  return 0;
}
