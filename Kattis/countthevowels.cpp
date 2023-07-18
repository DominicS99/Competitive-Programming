#include <iostream>
using namespace std;

int main() {
  string s, vowels = "AEIOUaeiou";
  getline(cin, s);
  int res = 0;
  for (char c : s) {
    if (vowels.find(c) != string::npos) res++;
  }
  cout << res << endl;
  return 0;
}
