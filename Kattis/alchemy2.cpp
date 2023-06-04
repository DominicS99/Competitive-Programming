#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.length(), m = n/2;
  int res = 0;

  vector<vector<int>> memo(m, vector<int>(2, -1));

  function<int(int, int)> solve = [&] (int a, int b) {
    if (a >= m) return 0;
    auto &res = memo[a][b];
    if (res > -1) return res;

    if (b != 1 && s[a] == s[n-1-a]) return res = solve(a+1, 0);
    if (s[a+1] != s[n-a-2]) return res = min(solve(a+2, 0), solve(a+1, 0)) + 1;

    return res = min(solve(a+1, 1) + 1, solve(a+2, 0) + 2);
  };

  cout << solve(0, 0) << endl;
  return 0;
}
