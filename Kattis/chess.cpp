#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  vector<int> diag = {1, 1, -1, -1, 1};
  int t, num;
  char letter;
  cin >> t;

  while (t--) {
    int res = 0;
    vector<string> states(2);
    vector<string> moves;
    for (int i = 0; i < 2; i++) {
      cin >> letter >> num;
      states[i] = letter + to_string(num);
    }
    int startL = states[0][0] - 'A';
    int startN = states[0][1] - '0' - 1;
    int endL = states[1][0] - 'A';
    int endN = states[1][1] - '0' - 1;

    if ((startL + startN)%2 != (endL + endN)%2) {
      cout << "Impossible" << endl;
      continue;
    }
    
    moves.push_back(states[0]);

    if (startL != endL || startN != endN) {
      if (abs(startL - endL) == abs(startN - endN)) {
        res = 1;
      } else {
        vector<vector<int>> board(8, vector<int>(8, 0));
        for (int i = 0; i < 4; i++) {
          int r = startN, c = startL;
          while (r >= 0 && c >= 0 && r < 8 && c < 8) {
            board[r][c] = 1;
            r += diag[i];
            c += diag[i+1];
          }
        }

        for (int i = 0; i < 4; i++) {
          int r = endN, c = endL;
          bool f = false;
          while (r >= 0 && c >= 0 && r < 8 && c < 8) {
            if (board[r][c] > 0) {
              moves.push_back(char(c + 'A') + to_string(r + 1));
              f = true;
              break;
            }
            r += diag[i];
            c += diag[i+1];
          }
          if (f) break;
        }
        res = 2;
      }
      moves.push_back(states[1]);
    }

    cout << res << " ";
    for (string it : moves) {
      cout << it[0] << " " << it[1] << " ";
    }
    cout << endl;
  }
  
  return 0;
}
