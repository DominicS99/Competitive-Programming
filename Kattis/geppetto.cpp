#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pii> d(m);
  for (auto &it : d) {
    int l, r;
    cin >> l >> r;
    it.first = pow(2, l-1);
    it.second = pow(2, r-1);
  }

  int count = 0;

  for (int i = 0; i < (1<<n); i++) {
    for (int j = 0; j < m; j++) {
      if ((i & d[j].first) && (i & d[j].second)) {
        count++;
        break;
      }
    }
  }

  cout << (1<<n) - count << endl;
  return 0;
}
