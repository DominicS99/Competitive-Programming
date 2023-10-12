#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

// grave = wall (1e9)
// hole = time/space warp ig
// grass = reg+1?

int main() {
  ios::sync_with_stdio(0); cin.tie(NULL);
  vector<int> dir = {1, 0, -1, 0, 1};
  int M, N, G, X, Y, X2, Y2, T, E;
  while (1) {
    cin >> M >> N;
    if (M == 0 && N == 0) break;
    vector<vector<pii>> al(M*N);
    vector<vector<int>> grid(M, vector<int>(N, 1));
    cin >> G;
    for (int i = 0; i < G; i++) {
      cin >> X >> Y;
      grid[X][Y] = 0;
    }
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        for (int d = 0; d < 4; d++) {
          int r = i + dir[d];
          int c = j + dir[d+1];
          if (r < 0 || c < 0 || r >= M || c >= N) continue;
          if (grid[r][c] == 0) continue;
          al[j + i*N].push_back({c + r*N, 1});
        }
      }
    }
    
    cin >> E;
    for (int i = 0; i < E; i++) {
      cin >> X >> Y >> X2 >> Y2 >> T;
      al[Y + X*N].clear();
      al[Y + X*N].push_back({Y2 + X2*N, T});
    }

    vector<int> dist(M*N);
    for (int i = 0; i < M*N; i++) {
      dist[i] = 1e9;
    }
    dist[0] = 0;

    for (int i = 0; i < M*N-1; i++) {
      bool modified = false;
      for (int u = 0; u < M*N-1; u++) {
        if (dist[u] == 1e9) continue;
        for (auto &[v, t] : al[u]) {
          if (dist[u]+t >= dist[v]) continue;
          dist[v] = dist[u]+t;
          modified = true;
        }
      }
      if (!modified) break;
    }

    bool negCycle = false;
    for (int u = 0; u < M*N-1; u++) {
      if (dist[u] == 1e9) continue;
      for (auto &[v, t] : al[u]) {
        if (dist[v] > dist[u]+t) negCycle = true;
      }
    }

    if (negCycle) {
      cout << "Never" << endl;
      continue;
    }

    if (dist[M*N-1] == 1e9) {
      cout << "Impossible" << endl;
    } else {
      cout << dist[M*N-1] << endl;
    }
  }
  return 0;
}