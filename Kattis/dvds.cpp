#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> d(n);
    for (auto &it : d) cin >> it;

    int curr = 1, res = 0;
    for (int &it : d) {
      it == curr ? curr++ : res++;
    }

    cout << res << endl;
  }

  return 0;
}
