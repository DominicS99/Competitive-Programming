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
    int n, a, b;
    cin >> n;
    auto cmp = [](pii &a, pii &b) {
      if (a.first == b.first) return a.second < b.second;
      return a.first > b.first;
    };
    priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp), newPq(cmp);
    for (int i = 0; i < n; i++) {
      cin >> a >> b;
      pq.emplace(a, b);
    }
 
    LL res = 0;
    while (!pq.empty()) {
      auto [x, y] = pq.top(); pq.pop();
      if (x <= newPq.size()) continue;
      newPq.emplace(x, y);
      res += y;
      while (!newPq.empty()) {
        auto [newX, newY] = newPq.top();
        if (newX >= newPq.size()) break;
        newPq.pop();
      }
    }
 
    cout << res << endl;
  }
  
  return 0;
}
