#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (!n) break;
        vector<string> units(n);
        for (auto &s : units) cin >> s;
        unordered_map<string, vector<pair<string, int>>> m;
        for (int i = 1; i < n; i++) {
            vector<string> row(4);
            for (auto &x : row) cin >> x;
            m[row[0]].push_back({row[3], stoi(row[2])});
            m[row[3]].push_back({row[0], stoi(row[2])*-1});
        }
        
        vector<pair<int, string>> res;
        for (int i = 0; i < n; i++) {
            bool f = true;
            res.clear();
            res.push_back({1, units[i]});
            queue<pair<int, string>> q;
            q.push({1, units[i]});

            unordered_set<string> vis;
            vis.insert(units[i]);

            while (!q.empty()) {
                auto [x, s] = q.front(); q.pop();
                for (auto &[nextS, c] : m[s]) {
                    if (vis.count(nextS)) continue;
                    if (c < 0) {
                        if (x < c || x%c != 0) {
                            f = false;
                            break;
                        }
                        int switchBack = c*-1;
                        res.emplace_back(x/switchBack, nextS);
                        q.emplace(x/switchBack, nextS);
                    } else {
                        res.emplace_back(x*c, nextS);
                        q.emplace(x*c, nextS);
                    }
                    vis.insert(nextS);
                }
                if (!f) break;
            }
            if (f) break;
        }
        sort(res.begin(), res.end());
        if (!res.empty()) cout << res[0].first << res[0].second;
        for (int i = 1; i < n; i++) {
            cout << " = " << res[i].first << res[i].second;
        }
        cout << "\n";
    }
    return 0;
}