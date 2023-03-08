#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

int main() {
  int s, t, n;
  cin >> s >> t >> n;

  vector<pii> blades(n);
  for (int i = 0; i < n; i++) {
    cin >> blades[i].first >> blades[i].second;
  }

  return 0;
}

/*
10->5: 10
5->4: 2
4->2: 5
2->1: 

*/
