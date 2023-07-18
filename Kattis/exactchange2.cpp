#include <iostream>
#include <vector>
using namespace std;

int SIZE = 20001;
void solve() {
  int W, n;
  cin >> W >> n;
  vector<int> d(n);
  for (auto &it : d) cin >> it;

  vector<int> memo(SIZE, 1e9);
  memo[0] = 0;
  for (int &x : d) {
    for (int y = SIZE-x-1; y > -1; y--) {
      if (memo[y] == 1e9) continue;
      memo[x+y] = min(memo[x+y], memo[y]+1);
    }
  }

  for (int i = W; i < SIZE; i++) {
    if (memo[i] == 1e9) continue;
    cout << i << " " << memo[i] << endl;
    return;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
