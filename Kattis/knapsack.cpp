#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int C, n, res, w;
  while (cin >> C >> n) {
    vector<int> val(n), weight(n);
    for (int i = 0; i < n; i++) cin >> val[i] >> weight[i];

    vector<vector<int>> memo(n+1, vector<int>(C+1, 0));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= C; j++) {
        if (weight[i-1] <= j) {
          memo[i][j] = max(val[i-1] + memo[i-1][j-weight[i-1]], memo[i-1][j]);
        } else {
          memo[i][j] = memo[i-1][j];
        }
      }
    }

    vector<int> items;
    res = memo[n][C];
    w = C;
    for (int i = n; i > 0 && res > 0; i--) {
      if (res == memo[i-1][w]) continue;
      res -= val[i-1];
      w -= weight[i-1];
      items.push_back(i-1);
    }

    cout << items.size() << endl;
    for (auto &it : items) cout << it << " ";
    cout << endl;
  }

  return 0;
}
