/*
  Worked on a DP idea with help from Donald Dong.
  
  Idea is to separte the array into three sections (left, mid, right).
  Always find the next highest on the left side, dp the right side solution ahead of time.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int k, n;
  cin >> k;
  vector<int> res;

  for (int x = 1; x <= k; x++) {
    cin >> n;
    vector<int> d(n);
    for (auto &it : d) cin >> it;
    bool found = false;

    set<int> myLeft;
    vector<int> memo(n+1, -1);
    for (int i = n-1; i > -1; i--) {
      memo[i] = max(d[i], memo[i+1]);
    }

    myLeft.insert(d[0]);
    for (int i = 1; i < n; i++) {
      auto & curr = d[i];
      int nextLow = *myLeft.upper_bound(curr);
      if (nextLow > curr && nextLow < memo[i]) {
        found = true;
        break;
      }
      myLeft.insert(curr);
    }

    if (found) {
      res.push_back(x);
    }
  }

  cout << res.size() << endl;
  for (auto it : res) cout << it << endl;
  
  return 0;
}
