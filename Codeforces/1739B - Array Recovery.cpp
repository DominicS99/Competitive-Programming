#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int t, n, d;
  cin >> t;
  while (t--) {
    bool fail = false;
    vector<int> a;
    cin >> n;
    
    while (n--) {
      cin >> d;
      if (a.empty()) {
        a.push_back(d);
      } else {
        if (d != 0 && a.back() - d >= 0) {
          fail = true;
        } else {
          a.push_back(a.back() + d);
        }
      }
    }
      
    if (fail) {
      cout << -1;
    } else {
      for (int it : a) {
        cout << it << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}
