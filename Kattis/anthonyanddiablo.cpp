#include <bits/stdc++.h>
using namespace std;

int main() {
  double a, b;
  cin >> a >> b;
  double p = 2.0 * sqrt(M_PI * a);

  if (p > b) {
    cout << "Need more materials!";
  } else {
    cout << "Diablo is happy!";
  }
  return 0;
}
