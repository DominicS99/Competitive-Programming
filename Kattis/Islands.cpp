#include <bits/stdc++.h>
using namespace std;

/* 
Stuff I knew, but practiced with this:
- Directions algorithm. Very useful to have this created quickly in order to check 4 adj directions.
- Checking every row + col to check whether it's land, do a dfs if so.

Stuff I learned with this:
- Functions within main (needs #include <functional>)
- Instead of a visited grid, you can just change any space visited to water to reduce space complexity
- Instead of making a 2D char array, you can make a 1D array of strings and take in each row that way
*/
int main() {
    vector<int> dir = {0,1,0,-1,0};
    int r, c, res = 0;
    cin >> r >> c;
    vector<string> g(r);
    for (auto &row : g) cin >> row;
    function<void(int, int)> dfs = [&](int i, int j) {
        if (g[i][j] == 'W') return;
        g[i][j] = 'W';
        for (int k = 0; k < 4; k++) {
            int x = i+dir[k];
            int y = j+dir[k+1];
            if (x < 0 || y < 0 || x >= r || y >= c) continue;
            dfs(x, y);
        }
    };
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (g[i][j] == 'L') {
                res++;
                dfs(i, j);
            }
        }
    }
    cout << res << endl;
    return 0;
}
