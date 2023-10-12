class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int memo[m+1][n+1];
        memset(memo, -1, sizeof(memo));

        function<int(int, int)> solve = [&] (int a, int b) {
            auto &res = memo[a][b];
            if (res != -1) return res;
            if (a == m) return res = n-b;
            if (b == n) return res = m-a;
            if (word1[a] == word2[b]) return res = solve(a+1, b+1);

            return res = min(solve(a+1, b), solve(a, b+1)) + 1;
        };

        return solve(0, 0);
    }
};