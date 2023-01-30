// Slower, but easier to implement

#include <bits/stdc++.h>
using namespace std;

int givePoints(int x) {
  if (x < 3) return 0;
  if (x < 5) return 1;
  if (x == 5) return 2;
  if (x == 6) return 3;
  if (x == 7) return 5;
  return 11;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  vector<int> dir = {1, 0, -1, 0, 1, 1, -1, -1, 1};
  int w,b;
  int n = 4;
  cin >> w;
  vector<string> words(w);
  for (auto &it : words) cin >> it;

  cin >> b;
  while (b--) {
    int score = 0, wordCount = 0;
    string bestWord;
    vector<string> board(n);
    for (auto &it : board) cin >> it;
    vector<bool> found(w, 0);

    function <bool (string, int, int, int)> dfs = [&] (string word, int index, int x, int y) {
      if (index == word.length()) return true;

      for (int i = 0; i < 8; i++) {
        int r = x + dir[i];
        int c = y + dir[i+1];

        if (r < 0 || c < 0 || r >= n || c >= n) continue;
        auto & dice = board[r][c];
        if (dice != word[index]) continue;
        
        dice = '#';
        bool temp = dfs(word, index+1, r, c);
        dice = word[index];
        if (temp) return true;
      }
      return false;
    };

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < w; k++) {
          auto & word = words[k];
          auto & dice = board[i][j];
          if (word[0] != dice) continue;
          if (found[k]) continue;
          dice = '#';
          if (dfs(word,1,i,j)) {
            found[k] = true;
            score += givePoints(word.length());
            if (bestWord.length() < word.length() ||
              (bestWord.length() == word.length() && 
              bestWord > word)) {
              bestWord = word;
            }
            wordCount++;
          }
          dice = word[0];
        }
      }
    }
    
    cout << score << " " << bestWord << " " << wordCount << endl;
  }

  return 0;
}
