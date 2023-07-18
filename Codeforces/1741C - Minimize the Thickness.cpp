#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
 
  int c, n, a;
 
  cin >> c;
 
  while (c--) {
    cin >> n;
    vector<int> sums(n);
    int curr = 0, low = n;
    for (int i = 0; i < n; i++) {
      cin >> a;
      curr = a+curr;
      sums[i] = curr;
    }
 
    for (int i = 0; i < n-1; i++) {
      if (sums.back()%sums[i] == 0) {
        int top = i+1;
        int end = i;
        for (int j = i+1; j < n; j++) {
          if (sums[j]-sums[end] == sums[i]) {
            top = max(top,j-end);
            end = j;
          }
        }
        if (end == n-1) {
          low = min(low, top);
        }
      }
    }
    cout << low << "\n";
  }
  
  return 0;
}
