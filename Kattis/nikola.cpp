#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  for (auto &it : d) cin >> it;

  vector<vector<int>> memo(n+1, vector<int>(n+1, 1e9));

  function<int (int, int)> solve = [&] (int jump, int square) {
    if (memo[jump][square] != 1e9) return memo[jump][square];
    if (square == n) return d[n-1];

    int a = square+jump+1;
    int left = a > n ? 1e9 : solve(jump+1, a);

    int b = square-jump;
    int right = b < 1 ? 1e9 : solve(jump, b);

    return memo[jump][square] = min(left, right) + d[square-1];
  };

  cout << solve(1, 2) << endl;
  return 0;
}
