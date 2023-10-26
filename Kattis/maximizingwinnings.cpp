#include <iostream>
#include <vector>
#include <functional>
#include <limits.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    while (cin >> n) {
        if (n == 0) break;
        vector<vector<int>> grid(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
        cin >> m;

        vector<vector<int>> memo(n, vector<int>(m+1, -1));
        function<int(int, int)> high = [&] (int i, int k) {
            auto &res = memo[i][k];
            if (res != -1) return res;
            if (k == m) return res = 0;
            res = 0;
            for (int x = 0; x < n; x++) {
                res = max(res, high(x, k+1) + grid[i][x]);
            }
            return res;
        };

        vector<vector<int>> memo2(n, vector<int>(m+1, -1));
        function<int(int, int)> low = [&] (int i, int k) {
            auto &res = memo2[i][k];
            if (res != -1) return res;
            if (k == m) return res = 0;
            res = INT_MAX;
            for (int x = 0; x < n; x++) {
                res = min(res, low(x, k+1) + grid[i][x]);
            }
            return res;
        };

        cout << high(0, 0) << " " << low(0, 0) << "\n";
    }
    return 0;
}