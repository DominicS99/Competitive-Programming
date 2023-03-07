/*
  Idea: Once you realize you can use 2 pointer to go from O(n^2) -> O(n), the problem becomes simple.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, l, h;
  cin >> n >> l >> h;
  vector<int> d(n);
  for (auto &it : d) cin >> it;

  int high = 0, low = n;
  for (int s = l; s <= h; s++) {
    vector<int> counts(s, 0);
    int l = 0, r = 0;
    int profit = 0;
    while (r < s) {
      profit += d[r];
      if (profit > 0) counts[r]++;
      r++;
    }
    while (r < n) {
      profit = profit + d[r] - d[l];
      if (profit > 0) counts[r%s]++;
      r++;
      l++;
    }
    while (l < r) {
      profit -= d[l];
      if (profit > 0) counts[l%s]++;
      l++;
    }

    high = max(high, *max_element(counts.begin(), counts.end()));
    low = min(low, *min_element(counts.begin(), counts.end()));
  }

  cout << low << " " << high << endl;

  return 0;
}
