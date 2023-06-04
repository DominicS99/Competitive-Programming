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
    double n, k;
    cin >> n >> k;
    vector<int> d(n, 0);
    d[n-1] = 1;
    for (int i = 0; i < n; i += k) {
      d[i] = 1;
    }
    cout << (accumulate(d.begin(), d.end(), 0)) << endl;
  }
  
  return 0;
}
