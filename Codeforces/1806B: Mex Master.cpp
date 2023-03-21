#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
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
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n;
    vi d(n);
    for (auto &it : d) cin >> it;
 
    int zeroCount = 0;
    int oneCount = 0;
    int highCount = 0;
    for (auto &x : d) {
      if (!x) {
        zeroCount++;
      } else if (x == 1) {
        oneCount++;
      } else {
        highCount++;
      }
    }
 
    if (zeroCount <= ceil(n/2.0)) {
      cout << 0 << endl;
      continue;
    }
 
    if (oneCount && !highCount) {
      cout << 2 << endl;
    } else {
      cout << 1 << endl;
    }
  }
  return 0;
}
