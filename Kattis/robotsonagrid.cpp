#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int MOD = pow(2, 31) - 1;

int main() {
    int n; cin >> n;
    vector<string> grid(n);
    vector<int> dir = {1, 0, 1};
    for (auto &it : grid) cin >> it;

    long long memo[1000][1000];
    memset(memo, -1, sizeof(memo));
    function<long long(int, int)>  solve = [&] (int x, int y) {
        auto &res = memo[x][y];
        if (res != -1) return res;
        if (x == n-1 && y == n-1) return res = 1;
        res = 0;
        for (int i = 0; i < 2; i++) {
            int r = x + dir[i];
            int c = y + dir[i+1];

            if (r >= n || c >= n) continue;
            if (grid[r][c] == '#') continue;
            res = (res + solve(r, c))%MOD;
        }
        return res;
    };

    int res = solve(0, 0);

    function<bool(int, int)> bfs = [&] (int a, int b) {
        vector<int> dir2 = {1, 0, -1, 0, 1};
        queue<pii> q; q.emplace(a, b);
        grid[a][b] = '#';
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int r = x + dir2[i];
                int c = y + dir2[i+1];

                if (r < 0 || c < 0 || r >= n || c >= n) continue;
                if (grid[r][c] == '#') continue;
                if (r == n-1 && c == n-1) return true;

                grid[r][c] = '#';
                q.emplace(r, c);
            }
        }
        return false;
    };

    if (res > 0) {
        cout << res << "\n";
    } else if (bfs(0, 0)) {
        cout << "THE GAME IS A LIE\n";
    } else {
        cout << "INCONCEIVABLE\n";
    }

    return 0;
}