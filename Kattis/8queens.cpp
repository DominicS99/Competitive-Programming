/**
 * @file 8queens.cpp
 * @author Dominic Sagen
 * @brief If you find this because you're failing case 3...hello! Line 46 should help.
 * 
 * @version 0.1
 * @date 2023-10-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> dir = {1, 0, -1, 0, 1, 1, -1, -1, 1};

bool invalidate(int x, int y, vector<string> &grid) {
    for (int i = 0; i < 8; i++) {
        for (int j = 1; j < 8; j++) {
            int r = x + dir[i]*j;
            int c = y + dir[i+1]*j;

            if (r < 0 || c < 0 || r >= 8 || c >= 8) break;
            if (grid[r][c] == '*') return true;
        }
    }
    return false;
}

int main() {
    vector<string> grid(8);
    for (auto &x : grid) cin >> x;

    bool invalid = false;
    int count = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (grid[i][j] == '.') continue;
            count++;
            invalid |= invalidate(i, j, grid);
        }
    }

    cout << (invalid || (count != 8) ? "invalid" : "valid") << "\n";
    return 0;
}