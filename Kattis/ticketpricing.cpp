/*
  My first DP solution without any prior knowledge, references, or hints!
*/

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;

int main() {
  int n, w;
  cin >> n >> w;
  vector<vector<pii>> info(w+1);

  int x;
  for (int i = 0; i <= w; i++) {
    cin >> x;
    vector<pii> curr(x);
    for (auto &it : curr) cin >> it.first;
    for (auto &it : curr) cin >> it.second;
    info[i] = curr;
  }
  
  vector<vector<LL>> memo(w+2, vector<LL>(n+1, -1));
  function<LL(int, int)> solve = [&] (int l, int seats) {
    if (l > w) return (LL)0;
    if (memo[l][seats] > -1) return memo[l][seats];
    LL res = 0;
    for (auto &[val, s] : info[l]) {
      int seatsLeft = min(seats, s);
      res = max(res, solve(l+1, seats-seatsLeft) + val*seatsLeft);
    }

    return memo[l][seats] = res;
  };

  LL res = 0, firstPrice = info[0][0].first;
  for (auto &[val, s] : info[0]) {
    if (!n) break;
    int seatsLeft = min(n, s);
    LL newSum = solve(1, n-seatsLeft) + val*seatsLeft;
    if (res < newSum) {
      res = newSum;
      firstPrice = val;
    }
  }

  cout << res << endl;
  cout << firstPrice << endl;
  return 0;
}
