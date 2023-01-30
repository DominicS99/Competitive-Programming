#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
  vector<string> changes = {"@", "8", "(", "|)", "3", "#", "6", 
                            "[-]", "|", "_|", "|<", "1", "[]\\/[]", 
                            "[]\\[]", "0", "|D", "(,)", "|Z", "$", 
                            "']['", "|_|", "\\/", "\\/\\/", "}{", "`/", "2"};
  unordered_map<int, string> m;
  for (int i = 'A'; i <= 'Z'; i++) {
    m[i] = changes[i-'A'];
    m[i+32] = changes[i-'A'];
  }

  string s, res;
  getline(cin, s);

  for (char c : s) {
    if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
      res += m[c];
    } else {
      res += c;
    }
  }

  cout << res << endl;
  return 0;
}
