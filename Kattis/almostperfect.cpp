#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int n;
  
  while (cin >> n) {
    int root = sqrt(n), res = 1, lim = n+2;
    for (int i = 2; i <= root; i++) {
      if (n%i) continue;
      
      int j = n/i;
      if (j != i) res += j;
      res += i;
      
      if (res > lim) break;
    }

    cout << n << " ";
    if (abs(res-n) > 2) {
      cout << "not ";
    } else if (res != n) {
      cout << "almost ";
    }
    cout << "perfect" << endl;
  }
  return 0;
}
