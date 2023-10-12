// Just coded both ways instead of combining them. Made it easier for me to focus on the idea.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(NULL);
  string a, b;
  cin >> a >> b;
  int n = a.length(), res = 0;

  stack<int> s;
  bool opt1 = false;
  for (int i = 0; i < n; i++) {
    int currDiff = b[i] - a[i];
    if (currDiff == 0 || opt1 && currDiff < 0 || !opt1 && currDiff > 0) {
      if (!s.empty()) res += abs(s.top());
      while (!s.empty()) s.pop();
    }
    
    if (currDiff > 0) {
      opt1 = true;
      if (!s.empty() && s.top() > currDiff) {
        res += abs(s.top() - currDiff);
        while (!s.empty() && s.top() > currDiff) s.pop();
      }
      s.push(currDiff);
    } else if (currDiff < 0) {
      opt1 = false;
      if (!s.empty() && s.top() < currDiff) {
        res += abs(s.top() - currDiff);
        while (!s.empty() && s.top() < currDiff) s.pop();
      }
      s.push(currDiff);
    }
  }

  if (!s.empty()) {
    res += abs(s.top());
  }

  cout << res << endl;
  return 0;
}