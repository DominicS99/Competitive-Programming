#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  
  int n, s, k;
  cin >> n >> s >> k;
  vector<int> fnd(n);
  for (auto &it : fnd) cin >> it;
  sort(fnd.begin(), fnd.end());

  int res = 0;
  vector<int> dist(n+1);
  dist[0] = INT_MAX;
  dist[n] = INT_MAX;
  for (int i = 1; i < n; i++) {
    dist[i] = fnd[i] - fnd[i-1];
    if (dist[i] < s) {
      res = -1;
      break;
    }
    dist[i] *= 2;
  }

  if (res > -1) {
    for (int i = 0; i < dist.size()-1; i++) {
      int length = min(min(dist[i], dist[i+1]-s), k);
      dist[i+1] -= length;
      res += length;
    }
  }

  cout << res << endl;
  return 0;
}
