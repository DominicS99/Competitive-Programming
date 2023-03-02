#include <iostream>
using namespace std;

int main() {
  int s1, s2, m1, m2;
  cin >> s1 >> s2 >> m1 >> m2;

  s1 = s2-s1;
  m1 = m2-m1;
  while (s1 != m1) {
    if (s1 < m1) {
      s1 += s2;
    } else {
      m1 += m2;
    }
  }

  cout << s1 << endl;
  return 0;
}
