#include <bits/stdc++.h>
using namespace std;

const int C = 30000;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  // First 2 lines of input
  int n, m, total;
  cin >> n;
  vector<int> cost(n);
  for (auto &it : cost) cin >> it;

  /*
    Parent holds previously used index for fast access in print

    Memo holds the current index, with a few exceptions:
      - -1 means we haven't visited this yet.
        We can safely set the parent to be currCost - cost[i];
          Note: currCost == j.
      - -2 means we have visited this, and we know it has dupes
      - -3 is only for the start, since we want a number that 
          doesn't fit the other criteria
  */
  vector<int> memo(C+1, -1), parent(C+1);
  memo[0] = -3;

  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= C; j++) {
      if (cost[i] > j) continue;
      if (memo[j] == -2) continue;

      int prev = memo[j - cost[i]];
      if (prev == -1) continue;
      if (prev == -2) {
        memo[j] = -2;
        continue;
      }

      if (memo[j] == -1) {
        memo[j] = i;
        parent[j] = j-cost[i];
        continue;
      }

      if (parent[j] != i) {
        memo[j] = -2;
      }
    }
  }

  // Recursive print function
  function <void (int)> print = [&] (int i) {
    if (i == 0) return;
    print(parent[i]);
    cout << memo[i]+1 << " ";
  };

  // Run queries after DP is completed
  cin >> m;
  while (m--) {
    cin >> total;
    if (memo[total] == -1) {
      cout << "Impossible";
    } else if (memo[total] == -2) {
      cout << "Ambiguous";
    } else {
      print(total);
    }
    cout << endl;
  }

  return 0;
}
