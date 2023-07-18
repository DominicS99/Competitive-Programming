#include <iostream>
using namespace std;
 
int main() {
  int c, l, w;
 
  cin >> c;
  while (c--) {
    cin >> l >> w;
    if (l == 1 || w == 1) {
      cout << "1 1";
    } else if (l < 4 && w < 4) {
      cout << "2 2";
    } else {
      cout << l << " " << w;
    }
    cout << "\n";
  }
}
