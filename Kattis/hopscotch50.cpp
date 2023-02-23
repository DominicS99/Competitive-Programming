/*
  Idea: Store all coordinates based off their numeric value, then figure out the min distance to each next value.
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  
  int n, k, val;
  int res = INT_MAX;
  cin >> n >> k;

  if (k == 1) {
    cout << "0\n";
    return 0;
  }

  vector<vector<pii>> coordinates(k+1);
  vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> val;
      coordinates[val].emplace_back(i, j);
    }
  }

  for (pii curr : coordinates[1]) dist[curr.first][curr.second] = 0;

  for (int i = 2; i <= k; i++) {
    if (coordinates[i].empty()) break;
    
    for (pii curr : coordinates[i]) {
      for (pii prev : coordinates[i-1]) {
        int totalDist = dist[prev.first][prev.second] + 
          abs(prev.first - curr.first) + 
          abs(prev.second - curr.second);

        if (i == k) {
          res = min(res, totalDist);
        } else {
          auto & currDist = dist[curr.first][curr.second];
          currDist = min(currDist, totalDist);
        }
        
      }
    }
  }

  cout << (res == INT_MAX ? -1 : res) << endl;
  return 0;
}
