#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(NULL);
  int size = 3601;
  int __t;
  cin >> __t;
  
  while (__t--) {
    int n, t;
    cin >> n >> t;
    vector<int> d(n);
    for (auto &it : d) cin >> it;

    if (t == 0) {
      cout << "0 0" << endl;
      continue;
    }

    vector<int> dist(size, 1e9);
    queue<int> q;
    q.push(0);

    int count = 0;
    dist[0] = count;

    while (!q.empty()) {
      count++;
      queue<int> newQ;

      while (!q.empty()) {
        int i = q.front(); q.pop();

        for (int j : d) {
          int c = i+j;
          if (c < 0) c = 0;
          if (c >= size) c = size-1;
          if (dist[c] <= count) continue;

          dist[c] = count;
          newQ.push(c);
        }
      }

      swap(q, newQ);
    }

    int diff = t;
    while (dist[diff] == 1e9) diff++;
    cout << dist[diff] << " " << diff-t << endl;
  }
  
  return 0;
}
