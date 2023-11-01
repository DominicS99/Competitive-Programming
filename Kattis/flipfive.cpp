#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int lim = (1<<9);
vector<int> memo(lim, -1);
vector<int> dir = {1, 0, -1, 0, 1};

int translateToKey(vector<string> &grid) {
    int res = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            res <<= 1;
            if (grid[i][j] == '*') res++;
        }
    }
    return res;
}

int convertGrid(int x, int y, vector<string> grid) {
    grid[x][y] = (grid[x][y] == '*' ? '.' : '*');
    for (int i = 0; i < 4; i++) {
        int r = x + dir[i];
        int c = y + dir[i+1];

        if (r < 0 || c < 0 || r >= 3 || c >= 3) continue;
        grid[r][c] = (grid[r][c] == '*' ? '.' : '*');
    }
    return translateToKey(grid);
}

vector<string> translateToGrid(int key) {
    vector<string> res(3, "...");
    for (int i = 2; i >= 0; i--) {
        for (int j = 2; j >= 0; j--) {
            if (key%2) res[i][j] = '*';
            key /= 2;
        }
    }
    return res;
}

void solve(int key) {
    memo[key] = 0;
    int turn = 1;

    queue<int> q;
    q.push(key);

    while (!q.empty()) {
        queue<int> newQ;
        while (!q.empty()) {
            auto x = q.front(); q.pop();
            vector<string> grid = translateToGrid(x);

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int nxtKey = convertGrid(i, j, grid);
                    if (memo[nxtKey] != -1) continue;

                    memo[nxtKey] = turn;
                    newQ.push(nxtKey);
                }
            }
        }
        swap(q, newQ);
        turn++;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    solve(0);

    int _t; cin >> _t;
    while (_t--) {
        vector<string> grid(3);
        for (auto &x : grid) cin >> x;
        int key = translateToKey(grid);
        cout << memo[key] << "\n";
    }
    return 0;
}