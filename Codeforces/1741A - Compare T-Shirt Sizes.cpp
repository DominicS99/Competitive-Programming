#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
 
  int c;
  string a,b;
 
  cin >> c;
 
  while (c--) {
    cin >> a >> b;
 
    if (a.back() == b.back()) {
      if (a.length() == b.length()) {
        cout << "=";
      } else {
        if (a.back() == 'S') {
          if (a.length() > b.length()) {
            cout << "<";
          } else {
            cout << ">";
          }
        } else {
          if (a.length() > b.length()) {
            cout << ">";
          } else {
            cout << "<";
          }
        }
      } 
    } else if (a.back() > b.back()) {
      cout << "<";
    } else {
      cout << ">";
    }
 
    cout << "\n";
  }
  return 0;
}
