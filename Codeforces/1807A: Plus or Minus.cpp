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
    int a, b, c;
    cin >> a >> b >> c;
    cout << (a+b == c ? '+' : '-') << endl;
  }
  return 0;
}
