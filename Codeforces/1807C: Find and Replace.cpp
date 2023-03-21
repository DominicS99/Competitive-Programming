#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> G;
typedef vector<vector<pii>> AL;
 
template <class T> ostream& operator<<(ostream& os, const vector<T>& v) {
  bool isFirst = 1;
  for (auto &it : v) {
    if (!isFirst) os << " ";
    os << it;
    isFirst = 0;
  }
  return os;
};
 
inline auto split(const string& s) {
  stringstream ss(s);
  vector<string> res;
  for (string w; ss >> w;) res.push_back(w);
  return res;
}
 
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    unordered_map<char, char> m;
 
    for (int i = 0; i < n; i++) {
      if (!m.count(s[i])) {
        m[s[i]] = i%2 ? '0' : '1';
      }
      s[i] = m[s[i]];
    }
 
    bool f = true;
    for (int i = 1; i < n; i++) {
      if (s[i] == s[i-1]) f = false;
    }
 
    cout << (f ? "YES" : "NO") << endl;
  }
  return 0;
}
