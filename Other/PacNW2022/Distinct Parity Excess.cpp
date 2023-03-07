/*
  For some reason this problem didn't get added to Kattis, this solution should still be within the time limit.
*/

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1e7+1;

int main() {
  vector<int> counts(MAX, 0), res(MAX);
  for (int i = 2; i*2 < MAX; i++) {
    if (counts[i]) continue;
    for (int j = i+i; j < MAX; j+=i) counts[j]++;
  }

  res[1] = 0;
  for (int i = 2; i < MAX; i++) {
    if (!counts[i]) counts[i] = 1;
    res[i] = res[i-1] + (counts[i]%2 == 0 ? 1 : -1);
  }
  
  int n, a, b;
  cin >> n;
  while (n--) {
    cin >> a >> b;
    cout << res[b] - res[a-1] << endl;
  }

  return 0;
}
