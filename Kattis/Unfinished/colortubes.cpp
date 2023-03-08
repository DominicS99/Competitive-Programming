#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

int main() {
  int n, b;
  cin >> n;
  n++;
  vector<int> zeros;
  vector<vector<int>> tubes(n, vector<int>(3));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> tubes[i][j];
      if (tubes[i][j] == 0) zeros.push_back(i);
    }
  }

  vector<pii> res;
  function <void (int, int)> solve = [&] (int i, int c) {
    auto &mTube = tubes[i][1];
    if (mTube && c != mTube) {
      for (int z = 0; z < 3; z++) {
        int zeroTubeIndex = zeros[z];
        if (zeroTubeIndex == i) continue;
        
        for (auto &top : tubes[zeroTubeIndex]) {
          if (top) continue;
          
          top = mTube;
          mTube = 0;
          zeros.erase(zeros.begin()+z);
          zeros.push_back(i);
          sort(zeros.begin(), zeros.end());
          res.emplace_back(i, zeroTubeIndex);
          return;
        }
      }
    }
    for (int j = i; j < n; j++) {
      int k;
      for (k = 2; k > -1; k--) {
        if (tubes[j][k] == c) break;
      }
      if (k == -1) continue;

      for (k = 2; k > -1; k--) {
        if (tubes[j][k] == c) {
          
          break;
        }

        
      }
      
    }
  };
  
  for (int i = 0; i < n; i++) {
    int curr = tubes[i][0];
    while (curr != tubes[i][1] || curr != tubes[i][2]) solve(i, curr);
  }

  cout << res.size() << endl;
  for (auto &it : res) cout << it.first << " " << it.second << endl;
  return 0;
}

/*
2 0 0    2 0 0    2 3 0    2 3 2    2 3 2    2 3 2    2 3 0    2 0 0
1 1 0    1 1 3    1 1 3    1 1 3    1 1 3    1 1 3    1 1 3    1 1 3
2 3 3    2 3 0    2 0 0    0 0 0    3 1 0    3 1 2    3 1 2    3 1 2
2 1 3    2 1 3    2 1 3    2 1 3    2 0 0    0 0 0    2 0 0    2 3 0

2 2 0    2 2 0    2 2 2
1 1 3    1 1 3
3 1 0    3 1 3
2 3 0    2 0 0
*/
