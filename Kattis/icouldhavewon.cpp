#include <iostream>
#include <vector>
using namespace std;

int main() {
  string s;
  cin >> s;

  int n = s.length();
  vector<int> res;

  for (int i = 1; i <= n; i++) {
    int aCount = 0, bCount = 0;
    int aWin = 0, bWin = 0;
    for (char c : s) {
      if (c == 'A') {
        aCount++;
      } else {
        bCount++;
      }

      if (aCount == i || bCount == i) {
        if (aCount == i) aWin++;
        if (bCount == i) bWin++;
        aCount = 0;
        bCount = 0;
      }
    }

    if (aWin > bWin) res.push_back(i);
  }

  cout << res.size() << endl;
  for (auto &it : res) cout << it << " ";
  return 0;
}
