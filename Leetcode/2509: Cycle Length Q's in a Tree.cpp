#include <bits/stdc++.h>
using namespace std;

vector<int> cycleLengthQueries(int n, vector<vector<int>> &queries) {
  vector<int> res;
  for (auto &q : queries) {
    int count = 0;
    int l = q[0], r = q[1];
    while (l != r) {
      if (l > r)
        l /= 2;
      else
        r /= 2;
      count++;
    }
    res.push_back(count + 1);
  }

  return res;
}

// For testing purposes
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  int n1 = 3;
  vector<vector<int>> queries1 = {{5,3},{4,7},{2,3}};

  int n2 = 4;
  vector<vector<int>> queries2 = {{8,11}, {8,5}};

  int n = 2;
  vector<vector<int>> queries = {{1, 2}};

  vector<int> res = cycleLengthQueries(n2, queries2);
  for (auto &it : res) {
    cout << it << endl;
  }
}
