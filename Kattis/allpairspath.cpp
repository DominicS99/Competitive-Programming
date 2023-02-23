/*
  Idea: Practice for using Floyd-Warshall.
    Since weights can be negative, you have to prepare for a cycle that gets better infinitely as you go along.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  int n, m, q, u, v, w;

  while (1) {
    cin >> n >> m >> q;
    if (n == 0 && m == 0 && q == 0) break;
    vector<vector<int>> graph(n, vector<int>(n, 1e9));

    for (int i = 0; i < m; i++) {
      cin >> u >> v >> w;
      graph[u][v] = min(graph[u][v], w);
    }

    for (int i = 0; i < n; i++) graph[i][i] = 0;

    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (graph[i][k] == 1e9 || graph[k][j] == 1e9) continue;
          graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        }
      }
    }

    for (int k = 0; k < n; k++) {
      if (graph[k][k] > -1) continue;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (graph[i][j] == -1e9) continue;
          if (graph[i][k] == 1e9 || graph[k][j] == 1e9) continue;
          graph[i][j] = -1e9;
        }
      }
    }

    for (int i = 0; i < q; i++) {
      cin >> u >> v;
      if (graph[u][v] == 1e9) {
        cout << "Impossible" << endl;
      } else if (graph[u][v] == -1e9) {
        cout << "-Infinity" << endl;
      } else {
        cout << graph[u][v] << endl;
      }
    }

    cout << endl;
  }

  return 0;
}
