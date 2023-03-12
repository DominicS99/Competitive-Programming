#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(0); cin.tie(NULL);
  
  string s, order = "ATGC";
  int m, a, b;
  cin >> s >> m;
  int n = s.length()+1;

  vector<vector<int>> counts(n);
  counts[0] = {0, 0, 0, 0};
  for (int i = 1; i < n; i++) {
    counts[i] = counts[i-1];
    char c = s[i-1];
    for (int j = 0; j < 4; j++) {
      if (c != order[j]) continue;
      counts[i][j]++;
      break;
    }
  }

  while (m--) {
    cin >> a >> b;
    vector<pii> curr(4);
    for (int i = 0; i < 4; i++) {
      curr[i] = {counts[b][i] - counts[a-1][i], i};
    }

    sort(curr.begin(), curr.end(), [&](auto i, auto j) {
      return i.first > j.first;
    });
    
    for (auto &it : curr) cout << order[it.second];
    cout << endl;
  }

  return 0;
}
