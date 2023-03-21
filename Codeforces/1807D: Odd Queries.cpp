#include <bits/stdc++.h>
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
    int n, q, a, b, c;
    cin >> n >> q;
    n++;
    vector<int> d(n);
    for (int i = 1; i < n; i++) {
      cin >> a;
      d[i] = a%2;
    }
    for (int i = 1; i < n; i++) {
      d[i] += d[i-1];
    }
    int init = d[n-1]%2;
 
    while (q--) {
      cin >> a >> b >> c;
      int size = 1+b-a;
      int curr = d[b]-d[a-1];
      int change = c%2 ? size-curr : curr;
      int res = init + change;
 
      cout << (res%2 ? "YES" : "NO") << endl;
    }
    
  }
  return 0;
}
