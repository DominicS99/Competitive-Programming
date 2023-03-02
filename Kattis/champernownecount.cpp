#include <iostream>
#include <math.h>
using namespace std;

typedef long long int ll;

int main() {
  int n, k;
  cin >> n >> k;

  ll curr = 0, res = 0;
  for (int i = 1; i <= n; i++) {
    curr = (ll)(curr * pow(10, floor(log10(i))+1) + i)%k;
    if (curr == 0) res++;
  }

  cout << res << endl;
  
  return 0;
}
