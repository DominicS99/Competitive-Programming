/*
  Idea: Broke each section up and figured out parts one at a time. Took me a long time to get the logic correct.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct parent {
  int p;
  int level;
  int winner;
  int length;
  bool leaf;
  bool visited;
};

struct sortLevel {
  bool operator()(const parent &i, const parent &j) const {
    return i.level < j.level;
  }
};

bool sortLength(parent &i, parent &j) {
  return i.length > j.length;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  int tempNum;

  // Sort the players high to low
  int n, k;
  cin >> n >> k;
  vector<int> players(k);
  for (auto &it : players) cin >> it;
  sort(players.rbegin(), players.rend());

  // Create graph
  vector<parent> parents(n);
  parents[0].p = -1;
  parents[0].level = 0;
  parents[0].length = 0;
  for (int i = 1; i < n; i++) {
    cin >> tempNum;
    parents[i].p = tempNum;
    parents[i].level = parents[tempNum].level + 1;
    parents[i].length = 0;
    parents[i].leaf = true;
    parents[i].visited = false;
  }

  // Priority based on level, set non-leaves to false
  priority_queue<parent, vector<parent>, sortLevel> order;
  for (parent &p : parents) parents[p.p].leaf = false;

  // Add all leaves to order
  for (int i = 1; i < n; i++) {
    if (!parents[i].leaf) continue;
    parents[i].winner = i;
    order.push(parents[i]);
  }

  // Bottom-up DFS to "color" graph
  while (!order.empty()) {
    parent curr = order.top();
    order.pop();
    while (curr.p != -1 && !parents[curr.p].visited) {
      parents[curr.p].visited = true;
      parents[curr.p].winner = curr.winner;
      curr = parents[curr.p];
    }
  }

  // Find lengths of the tree
  for (int i = 1; i < n; i++) {
    if (!parents[i].leaf) continue;
    
    int curr = i;
    while (curr > -1 && parents[curr].winner == i) {
      parents[i].length++;
      curr = parents[curr].p;
    }
  }

  // Sort nodes by length
  sort(parents.begin(), parents.end(), sortLength);

  // Sum of all matches
  ll res = 0;
  for (int i = 0; i < k; i++) {
    res += (ll)players[i] * parents[i].length;
  }

  // Subtract final player because the final winner doesn't play again
  cout << res-players[0] << endl;

  return 0;
}
