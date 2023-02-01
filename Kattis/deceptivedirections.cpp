/*
  NOTE: This problem requires a lot of testing and careful reading to get an accepted solution. My solution is from a 3 hour practice session,
    with a number of revisions to make it successful. 
  
  General idea is to conduct a BFS to find which locations you can reach, while making sure you remove certain exceptions. Be careful of TLE issues,
    construct your own test cases to see what might be missing. My solution ended up working with 2 BFS's on the same turn based on what I was checking
    for.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int main() {
  vector<int> dir = {0, 1, 0, -1, 0};
  int m,n;
  string order;
  cin >> n >> m;
  vector<string> g(m);
  for (auto &it : g) cin >> it;
  cin >> order;

  queue<pii> q, badq;
  pii start;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (g[i][j] == 'S') start = {i,j};
    }
  }
  
  q.emplace(start);

  for (int i = 0; i < order.size(); i++) {
    queue<pii> newQ, newBadQ;

    while (!badq.empty()) {
      pii curr = badq.front();
      badq.pop();
      if (g[curr.first][curr.second] == 'C' || 
        g[curr.first][curr.second] == 'B') continue;
      g[curr.first][curr.second] = 'B';

      for (int d = 0; d < 4; d++) {
        int r = curr.first + dir[d];
        int c = curr.second + dir[d+1];

        if (g[r][c] != '.') continue;
        newBadQ.emplace(r,c);
      }
    }
    badq = newBadQ;
    
    while (!q.empty()) {
      pii curr = q.front();
      q.pop();
      if (g[curr.first][curr.second] == 'C') continue;
      if (g[curr.first][curr.second] != 'S') {
        g[curr.first][curr.second] = 'C';
      }

      for (int d = 0; d < 4; d++) {
        int r = curr.first + dir[d];
        int c = curr.second + dir[d+1];

        if (g[r][c] != '.') continue;
        
        if ((order[i] == 'E' && d == 0) ||
          (order[i] == 'S' && d == 1) ||
          (order[i] == 'W' && d == 2) ||
          (order[i] == 'N' && d == 3)) {
            badq.emplace(r,c);
            continue;
          }
        
        newQ.emplace(r,c);
      }
    }
    q = newQ;
  }

  while (!q.empty()) {
    pii curr = q.front();
    if (g[curr.first][curr.second] != 'C') {
      g[curr.first][curr.second] = '!';
    }
    q.pop();
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << (g[i][j] == 'C' || g[i][j] == 'B' ? '.' : g[i][j]);
    }
    cout << endl;
  }
  
  return 0;
}
