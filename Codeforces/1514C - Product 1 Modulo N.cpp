// Attempting to learn some number theory stuff. Coprime has been coming up a lot more than I'd expect.

#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
 
int main() {
  int n;
  cin >> n;
 
  ll curr = 1;
  vector<int> res;
  for (int i = 1; i < n; i++) {
    if (__gcd(i, n) == 1) {
      res.push_back(i);
      curr = (curr*i)%n;
    }
  }
  if (curr != 1) res.pop_back();
 
  cout << res.size() << endl;
  for (auto &it : res) cout << it << " ";
  cout << endl;
  return 0;
}
