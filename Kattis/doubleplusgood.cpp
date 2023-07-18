/*
  Complete Search idea felt more intuitive to me.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

inline vector<string> split(const string& s) {
  stringstream ss(s);
  vector<string> res;
  string w;
  
  while (getline(ss, w, '+')) {
    res.push_back(w);
  }
  return res;
}

int main() {
  string s;
  getline(cin, s);
  vector<string> line = split(s);
  int n = line.size();
  if (!n) {
    cout << 0 << endl;
    return 0;
  }
  n--;

  set<LL> res;
  int lim = 1<<n;
  for (int i = 0; i < lim; i++) {
    vector<LL> total;
    LL curr = stol(line[0]);
    for (int j = 0; j < n; j++) {
      if (i & (1<<j)) {
        total.push_back(curr);
        curr = 0;
      }
      curr = curr*pow(10, line[j+1].size()) + stol(line[j+1]);
    }
    total.push_back(curr);
    res.insert(accumulate(total.begin(), total.end(), 0));
  }

  cout << res.size() << endl;
  return 0;
}
