#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
 
  int c, n;
 
  cin >> c;
 
  while (c--) {
    cin >> n;
    if (n == 2) {
      cout << "2 1";
    } else if (n == 3) {
      cout << "-1";
    } else {
      cout << n-1 << " " << n << " ";
      for (int i = 1; i < n-1; i++) {
        cout << i << " ";
      }
    }
    cout << "\n";
  }
  
  return 0;
}
