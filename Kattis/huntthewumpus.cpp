#include <iostream>
#include <set>
using namespace std;

typedef pair<int, int> pii;

int main() {
  int s, x, y;
  cin >> s;

  set<pii> coord;
  while (coord.size() < 4) {
    s += (s/13 + 15);
    int temp = s;
    y = temp%10;
    temp /= 10;
    x = temp%10;
    if (coord.count({x, y})) continue;
    coord.emplace(x, y);
  }
  
  string a;
  int res = 0;
  while (cin >> a) {
    res++;
    x = a[0]-'0';
    y = a[1]-'0';
    if (coord.count({x, y})) {
      cout << "You hit a wumpus!" << endl;
      coord.erase({x, y});
    }

    int low = 1e9;
    for (auto &it : coord) {
      low = min(low, abs(it.first - x) + abs(it.second - y));
    }
    if (low == 1e9) break;
    cout << low << endl;
  }

  cout << "Your score is " << res << " moves." << endl;
  return 0;
}
