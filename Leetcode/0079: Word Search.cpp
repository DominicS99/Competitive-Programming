#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<int> dir = {0, 1, 0, -1, 0};
        int m = board.size();
        int n = board[0].size();
        bool res = false;
        vector<pair<int, int>> visit;
        function<void (int, int, string)> dfs = [&](int x, int y, string curr) {
            if (curr.empty()) {
                res = true;
                return;
            }
            for (int i = 0; i < 4; i++) {
                int r = dir[i]+x;
                int c = dir[i+1]+y;
                if (r < 0 || c < 0 || r >= m || c >= n) continue;
                if (board[r][c] == curr[0]) {
                    bool alreadyVisit = false;
                    for (auto &it : visit) {
                        if (it.first == r && it.second == c) alreadyVisit = true;
                    }
                    if (alreadyVisit) continue;
                    visit.push_back({r, c});
                    dfs(r, c, curr.substr(1, curr.size()-1));
                    visit.pop_back();
                }
            }
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    visit.push_back({i, j});
                    dfs(i, j, word.substr(1, word.size()-1));
                    visit.pop_back();
                }
            }
        }

        return res;
    }
};

int main() {
  vector<vector<char>> board2 = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
  string word2 = "SEE";

  Solution solution2;
  if (solution2.exist(board2, word2)) {
    cout << "Accepted\n";
  } else {
    cout << "Failed\n";
  }
  return 0;
}
