/*
  Idea: Store height paths, then backtrace to find the min path backwards.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

const int MAX = 1001;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> d(n);
    for (auto &it : d) cin >> it;

    if (n < 2) {
      cout << "IMPOSSIBLE" << endl;
      continue;
    }

    vector<vector<int>> memo(n, vector<int>(MAX, MAX));
    memo[0][d[0]] = d[0];
    for (int i = 1; i < n; i++) {
      for (int currHeight = 0; currHeight < MAX; currHeight++) {
        int prev = memo[i-1][currHeight];
        if (prev > MAX-1) continue;

        int &up = memo[i][currHeight + d[i]];
        up = max(prev, currHeight + d[i]);
        
        if (currHeight - d[i] > -1) {
          int & down = memo[i][currHeight - d[i]];
          down = min(down, prev);
        }
      }
    }
    
    if (memo[n-1][0] > MAX-1) {
      cout << "IMPOSSIBLE" << endl;
      continue;
    }

    string res = "D";
    int minHeight = memo[n-1][0];
    int curr = d[n-1];
    for (int i = n-2; i > 0; i--) {
      int val = d[i];
      if (memo[i-1][curr+val] <= minHeight) {
        curr += val;
        res += 'D';
      } else {
        curr -= val;
        res += 'U';
      }
      minHeight = memo[i-1][curr];
    }
    res += 'U';
    reverse(res.begin(), res.end());
    cout << res << endl;
  }

  return 0;
}
