#include <bits/stdc++.h>
using namespace std;

bool indexSort (pair<int, int> i, pair<int, int> j) {
  return i.second < j.second;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  // Input
  int n, k, num;
  cin >> n >> k;
  vector<pair<int, int>> d(n);
  for (int i = 0; i < n; i++) {
    cin >> num;
    d[i] = {num, i};
  }

  // Compress array into groups
  sort(d.begin(), d.end());
  for (int i = 0; i < n; i++) d[i].first = i/k;
  sort(d.begin(), d.end(), indexSort);

  // LIS
  vector<int> memo(n, INT_MAX);
  for (int i = 0; i < n; i++) {
    int pos = upper_bound(memo.begin(), memo.end(), d[i].first) - memo.begin();
    memo[pos] = d[i].first;
  }

  // # of elements that aren't apart of LIS
  int res = n;
  for (int i = 0; i < n; i++) {
    if (memo[i] == INT_MAX) break;
    res--;
  }

  cout << res << endl;
  return 0;
}
