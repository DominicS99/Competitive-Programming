#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(NULL);
  string s;
  cin >> s;
  string res(s.length(), 'A');
  cout << res + "WHO" << endl;
  return 0;
}
