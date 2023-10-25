/**
 * @file floodit.cpp
 * @author Dominic Sagen
 * @brief Very fun flood fill problem. Really straight-forward description
 * @version 0.1
 * @date 2023-10-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

vector<int> dir = {1, 0, -1, 0, 1};

int flood(vector<string> &grid, int n, char num) {
    char cLU = (grid[0][0] == 'A' ? 'B' : 'A');
    char cLP = (grid[0][0] == 'A' ? 'A' : 'B');
    queue<pii> q;
    grid[0][0] = cLU;
    q.emplace(0, 0);

    int res = 1;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int r = x + dir[i];
            int c = y + dir[i+1];

            if (r < 0 || c < 0 || r >= n || c >= n) continue;
            if (grid[r][c] == cLP || grid[r][c] == num) {
                grid[r][c] = cLU;
                q.emplace(r, c);
                res++;
            }
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int _t; cin >> _t;
    while (_t--) {
        int n; cin >> n;
        vector<string> grid(n);
        for (auto &it : grid) cin >> it;

        vector<int> counts(6, 0);
        int filled = flood(grid, n, grid[0][0]);
        int res = 0;
        while (filled < n*n) {
            vector<string> bestGrid;
            int countIndex = -1;
            for (int i = 1; i <= 6; i++) {
                vector<string> checkGrid = grid;
                int curr = flood(checkGrid, n, i+'0');
    
                if (curr > filled) {
                    countIndex = i-1;
                    filled = curr;
                    swap(bestGrid, checkGrid);
                }
            }
            res++;
            counts[countIndex]++;
            swap(grid, bestGrid);
        }

        cout << res << "\n";
        for (auto &x : counts) cout << x << " ";
        cout << "\n";
    }
    return 0;
}