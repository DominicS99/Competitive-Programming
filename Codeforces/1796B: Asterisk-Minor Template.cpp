#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  
  int t;
  string a, b;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    bool f = false;
    string res;
    int n = a.length()-1;
    
    if (a[0] == b[0]) {
      f = true;
      res = a[0];
      res += '*';
    } else if (a[n] == b[b.length()-1]) {
      f = true;
      res = "*";
      res += a[n];
    } else {
      for (int i = 0; i < n; i++) {
        if (b.find(a.substr(i, 2)) != string::npos) {
          f = true;
          res = "*";
          res += a.substr(i, 2);
          res += "*";
          break;
        }
      }
    }

    if (f) {
      cout << "YES\n" << res << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  
  return 0;
}
