#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  int t;
  string s;
  cin >> t;
  while (t--) {
    cin >> s;
    bool f = false;
    unordered_set<char> curr;
    
    for (int seven = 0; seven < 7; seven++) {
      curr.clear();
      int i = 0;
      
      while (i < s.length()) {
        if (curr.count(s[i])) break;

        if ((i+seven)%7 == 0) curr.clear();
        else curr.insert(s[i]);

        i++;
      }

      if (i == s.length()) {
        f = true;
        break;
      }
    }
    
    cout << f << endl;
  }

  return 0;
}
