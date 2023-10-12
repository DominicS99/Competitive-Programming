#include <iostream>
#include <vector>
using namespace std;

int main() {
    int c, n, x;
    cin >> c >> n;

    vector<vector<int>> d(2);
    if (n-- > 0) cin >> x;
    else x = c+1;
    for (int i = 1; i <= c; i++) {
        if (i == x) {
            d[0].push_back(i);
            if (n-- > 0) cin >> x;
            else x = c+1;
        } else {
            d[1].push_back(i);
        }
    }

    vector<vector<string>> res(2);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < d[i].size(); j++) {
            string s = to_string(d[i][j]);
            if (j+1 < d[i].size() && d[i][j]+1 == d[i][j+1]) {
                s += '-';
                while (j+1 < d[i].size() && d[i][j]+1 == d[i][j+1]) j++;
                s += to_string(d[i][j]);
            }
            res[i].push_back(s);
        }
    }

    for (int i = 0; i < 2; i++) {
        if (i == 0) cout << "Errors: ";
        else cout << "Correct: ";
        int m = res[i].size();
        
        if (m == 1) {
            cout << res[i][0];
        } else {
            int j = 0;
            for (; j+2 < m; j++) cout << res[i][j] << ", ";
            cout << res[i][j] << " and " << res[i][j+1];
        }

        cout << "\n";
    }
    return 0;
}