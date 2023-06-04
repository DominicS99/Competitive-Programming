// Curse my 2nd grade level math skills. Hopefully I'll be able to figure out a formula like this much faster in the future. Would make problems like this a lot more approachable for me.

#include <iostream>
using namespace std;

int main() {
  long long int t, n, d;
  cin >> t;
  while (t--) {
    cin >> n >> d;

    int sites = 0;
    while (1) {
      __int128 curr = 1;
      for (int i = 0; i < sites; i++) {
        curr *= (d+1);
      }
      if (n-curr <= 0) break;
      sites++;
    }
    
    cout << sites << endl;
  }

  return 0;
}
