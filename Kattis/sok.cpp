#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<double> d(6);
  for (auto &it : d) cin >> it;
  double low = 1e9;
  for (int i = 0; i < 3; i++) {
    low = min(low, d[i]/d[i+3]);
  }
  for (int i = 0; i < 3; i++) {
    printf("%.4f ", d[i] - (d[i+3]*low));
  }
  printf("\n");
  return 0;
}
