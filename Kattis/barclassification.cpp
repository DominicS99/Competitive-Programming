/*
  Idea: Sum each row and each column, then use that information to find how many bits
    must be flipped AT LEAST. 
    
  All that matters is whether it is possible to make a hor/ver line, not whether there's
    a way to make only one or the other.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  vector<string> g(n);
  bool hor = false, ver = false;
  for (auto &it : g) cin >> it;

  vector<int> rows(n, 0), cols(n, 0); 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      rows[i] += (g[i][j] - '0');
      cols[j] += (g[i][j] - '0');
    }
  }

  function <int (vector<int>&)> solve = [&](vector<int> & dir) {
    int sum = n - (2 * *max_element(dir.begin(), dir.end()));
    return accumulate(dir.begin(), dir.end(), sum);
  };

  if (solve(rows) <= n) hor = true;
  if (solve(cols) <= n) ver = true;

  if (hor == ver) {
    cout << "+" << endl;
  } else if (hor) {
    cout << "-" << endl;
  } else {
    cout << "|" << endl;
  }

  return 0;
}
