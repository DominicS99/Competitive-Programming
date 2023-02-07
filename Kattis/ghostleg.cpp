#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m, a;
  cin >> n >> m;
  vector<int> d(n+1);
  for (int i = 1; i <= n; i++) d[i] = i;
  
  while (m--) {
    cin >> a;
    swap(d[a], d[a+1]);
  }

  for (int i = 1; i <= n; i++) {
    cout << d[i] << endl;
  }

  return 0;
}
