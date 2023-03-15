#include <iostream>
using namespace std;

int main() {
  int n, i = 1;
  char c;
  cin >> n;
  n = 1 << (n+1);
  while (cin >> c) {
    i <<= 1;
    if (c == 'R') i++;
  }
  cout << n-i << endl;
  return 0;
}
