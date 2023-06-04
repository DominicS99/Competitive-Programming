// Fun problem, used a sliding window idea

#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int main() {
  ios::sync_with_stdio(0); cin.tie(NULL);
  LL n, m, k;
  cin >> n >> m >> k;
  vector<LL> d(n);
  for (auto &it : d) cin >> it;
  LL res = 0, curr = 0;
  vector<LL> trips(n, 0);

  for (int i = 0; i < min(m, n); i++) {
    if (curr == k) continue;
    LL rem = k-curr;
    trips[i] = min(d[i], rem);
    curr += trips[i];
  }
  res += curr;

  for (int i = m; i < n; i++) {
    LL prev = curr -= trips[i-m];
    for (int j = i; j > (i-m); j--) {
      if (curr == k) break;
      LL update = min(curr+d[j]-trips[j], k);
      trips[j] += update-curr;
      curr = update;
    }
    res += (curr - prev);
  }

  for (int i = max((LL)0, n-m); i < n; i++) {
    if (!trips[i]) continue;
    LL prev = curr -= trips[i];
    for (int j = n-1; j > i; j--) {
      if (curr == k) break;
      LL update = min(curr + d[j]-trips[j], k);
      trips[j] += update-curr;
      curr = update;
    }
    res += (curr - prev);
  }
  
  cout << res << endl;
  return 0;
}
