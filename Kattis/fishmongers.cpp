/*
  Idea: Find max kg fish and max money you can receive from a fishmonger using 2 priority queues.
  Please note that answers can be high when dealing with large amounts of multiplication and addition, therefore long is necessary.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  
  int n, m, a, b;
  ll res = 0;
  cin >> n >> m;
  priority_queue<ll> fish;
  while (n--) {
    cin >> a;
    fish.push(a);
  }

  priority_queue<pll> mongers;
  while (m--) {
    cin >> a >> b;
    mongers.emplace(b, a);
  }

  while (!mongers.empty() && !fish.empty()) {
    pll curr = mongers.top();
    res += (curr.first * fish.top());
    curr.second--;
    if (curr.second > 0) mongers.push(curr);
    mongers.pop();
    fish.pop();
  }

  cout << res << endl;
  return 0;
}
