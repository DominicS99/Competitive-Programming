#include <iostream>
#include <cstring>
using namespace std;

string word1, word2;
int m, n;
int memo[5001][5001];

int solve(int a, int b) {
    auto &res = memo[a][b];
    if (res != -1) return res;
    if (a == m) return res = n-b;
    if (b == n) return res = m-a;

    if (word1[a] == word2[b]) return res = solve(a+1, b+1);

    res = solve(a, b+1);
    res = min(res, solve(a+1, b));
    res = min(res, solve(a+1, b+1));
    return res += 1;
}

int main() {
    cin >> word1 >> word2;
    m = word1.length(), n = word2.length();
    memset(memo, -1, sizeof(memo));
    cout << solve(0, 0) << "\n";
    return 0;
}