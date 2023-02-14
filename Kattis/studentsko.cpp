#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> d(n);
  for (auto &it : d) cin >> it;

  vector<int> copied(n);
  copy(d.begin(), d.end(), copied.begin());
  sort(copied.begin(), copied.end());

  unordered_map<int, int> groups;
  for (int i = 0; i < n; i++) {
    groups[copied[i]] = i/k + 1;
  }

  for (int i = 0; i < n; i++) {
    d[i] = groups[d[i]];
  }

  vector<int> memo(n, INT_MAX);
  for (int i = 0; i < n; i++) {
    int pos = upper_bound(memo.begin(), memo.end(), d[i]) - memo.begin();
    memo[pos] = d[i];
  }

  int res = n;
  for (int i = 0; i < n; i++) {
    if (memo[i] == INT_MAX) break;
    res--;
  }

  cout << res << endl;
  return 0;
}
