#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  
  vector<int> ratings(1<<n);
  for (auto &it : ratings) cin >> it;

  sort(ratings.begin(), ratings.end());

  int res = 0;
  int l = 0, r = 1<<n;
  
  while (n--) {
    int m = l + (r-l)/2;
    int rightIndex = m;
    for (int i = l; i < m; i++) {
      if (ratings[i] + k < ratings[rightIndex]) continue;
      res++;
      rightIndex++;
    }
    l += m;
  }

  cout << res << endl;
  return 0;
}
