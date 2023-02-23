#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<bool> visited(n, 0);

  for (int i = 2; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      if (visited[j]) continue;
      if (--k == 0) {
        cout << j << endl;
        return 0;
      }
      visited[j] = 1;
    }
  }

  return 0;
}
