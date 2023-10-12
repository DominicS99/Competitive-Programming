// Tfw the hardest part of a problem is understanding the input structure

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    int t, m, n, s, x, y;
    cin >> t;
    while (t--) {
        cin >> n >> m >> s;
        vector<vector<vector<char>>> players(2, vector<vector<char>>(m, vector<char>(n)));
        vector<int> ships(2, 0);
        for (int p = 0; p < 2; p++) {
            for (int i = m-1; i >= 0; i--) {
                for (int j = 0; j < n; j++) {
                    cin >> players[p][i][j];
                    if (players[p][i][j] == '#') ships[p]++;
                }
            }
        }

        vector<pii> shots(s);
        for (auto &[x, y] : shots) cin >> y >> x;

        int curr = 1;
        for (auto &[x, y] : shots) {
            if (players[curr][x][y] == '#') {
                players[curr][x][y] = '_';
                if (--ships[curr] == 0) {
                    curr = (curr+1)%2;
                    if (curr == 1) break;
                }
            } else {
                curr = (curr+1)%2;
                if (curr == 1 && (!ships[0] || !ships[1])) break;
            }
        }

        if (ships[0] && !ships[1]) {
            cout << "player one wins\n";
        } else if (!ships[0] && ships[1]) {
            cout << "player two wins\n";
        } else {
            cout << "draw\n";
        }
    }
    return 0;
}