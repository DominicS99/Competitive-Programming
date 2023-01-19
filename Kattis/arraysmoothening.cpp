#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  
  int n, k, num;
  cin >> n >> k;

  // store freq of each number
  unordered_map<int, int> counts;
  while (n--) {
    cin >> num;
    counts[num]++;
  }

  // store frequencies in priority queue
  priority_queue<int> pq;
  for (auto it : counts) {
    pq.push(it.second);
  }

  // reduce top by 1 while k > 0
  while (k--) {
    pq.push(pq.top()-1);
    pq.pop();
  }

  cout << pq.top() << endl;
  return 0;
}
