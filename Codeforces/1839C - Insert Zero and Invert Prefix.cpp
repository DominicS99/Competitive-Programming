#include <bits/stdc++.h>
using namespace std;
 
typedef long long int LL;
typedef pair<int, int> pii;
 
inline vector<string> split(const string& s) {
  stringstream ss(s);
  vector<string> res;
  for (string w; ss >> w;) res.push_back(w);
  return res;
}
 
int main() {
  ios::sync_with_stdio(0); cin.tie(NULL);
  int _t;
  cin >> _t;
  while (_t--) {
    int n;
    cin >> n;
    vector<int> d(n);
    for (auto &it : d) cin >> it;
    reverse(d.begin(), d.end());
 
    if (d[0] == 1) {
      cout << "NO" << endl;
      continue;
    }
    vector<int> res;
    for (int i = 0, x = 0; i < n; i++) {
      if (d[i] == 1) {
        x++;
        if (i+1 == n) {
          res.push_back(x);
        } else {
          res.push_back(0);
        }
      } else if (d[i] == 0 && x > 0) {
        res.back() = x;
        x = 0;
        res.push_back(0);
      } else {
        res.push_back(0);
      }
    }
 
    cout << "YES" << endl;
    for (auto &it : res) cout << it << " ";
    cout << endl;
  }
  
  return 0;
}
