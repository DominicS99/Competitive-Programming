// Cycles and graph reduction...might be possible with DP but I couldn't quite get it to work that way.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

bool solve(int u, bool turn) {
  bool f = false;
  for (int v = 0; v < 3; v++) {
    if (!graph[u][v]) continue;
    
    graph[u][v]--;
    if (turn == solve(v, !turn)) f = true;
    graph[u][v]++;
  }
  return f ? turn : !turn;
}

int main() {
  int n;
  cin >> n;
  vector<string> d(n);
  for (auto &it : d) cin >> it;

  map<char, int> m;
  vector<vector<int>> counts(3, vector<int>(3, 0));
  for (int i = 0, x = 0; i < n; i++) {
    char l = d[i].front(), r = d[i].back();
    if (!m.count(l)) m[l] = x++;
    if (!m.count(r)) m[r] = x++;
    counts[m[l]][m[r]]++;
  }

  graph = counts;
  for (int i = 0; i < 3; i++) {
    graph[i][i] %= 2;
  }

  for (int i = 0; i < 3; i++) {
    for (int j = i+1; j < 3; j++) {
      int temp = min(graph[i][j], graph[j][i])-1;
      temp = max(temp, 0);
      graph[i][j] -= temp;
      graph[j][i] -= temp;
    }
  }

  int res = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (!graph[i][j]) continue;

      graph[i][j]--;
      res += solve(j, 0) * (counts[i][j]);
      graph[i][j]++;
    }
  }

  cout << res << endl;
  return 0;
}
