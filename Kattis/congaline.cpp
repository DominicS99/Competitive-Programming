#include <bits/stdc++.h>
using namespace std;

using List = list<int>;

int main() {
  ios::sync_with_stdio(0); cin.tie(NULL);
  int n, q;
  char c;
  cin >> n >> q;
  n *= 2;
  
  List order;
  vector<string> names(n);
  for (auto &it : names) cin >> it;
  for (int i = 0; i < n; i++) order.push_back(i);
  
  auto curr = order.begin();
  vector<List::iterator> its(n);
  int itIndex = 0;
  for (auto it = order.begin(); it != order.end(); it++) {
    its[itIndex++] = it;
  }

  for (int i = 0; i < q; i++) {
    cin >> c;
    switch (c) {
      case 'F':
        curr = prev(curr);
        break;
      case 'B':
        curr = next(curr);
        break;
      case 'R': {
        auto r = next(curr);
        if (r == order.end()) r = order.begin();
        
        its[*curr] = order.insert(order.end(), *curr);
        order.erase(curr);
        
        curr = r;
        break;
      } case 'C': {
        auto r = next(curr);
        if (r == order.end()) r = order.begin();

        int partner = (*curr) ^ 1;
        its[*curr] = order.insert(next(its[partner]), *curr);
        order.erase(curr);

        curr = r;
        break;
      } case 'P': {
        int partner = (*curr) ^ 1;
        cout << names[partner] << "\n";
        break;
      }
    }
  }

  cout << "\n";
  for (auto it : order) {
    cout << names[it] << "\n";
  }

  return 0;
}