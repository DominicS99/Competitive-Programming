class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int memo[m+1][n+1];
        memset(memo, -1, sizeof(memo));

        function<int(int, int)> solve = [&] (int a, int b) {
            auto &res = memo[a][b];
            if (res != -1) return res;

            // If a word is empty, the rest of the distance of the other word is the answer
            if (a == m) return res = n-b;
            if (b == n) return res = m-a;

            // same letter, continue
            if (word1[a] == word2[b]) return res = solve(a+1, b+1);

            // choose the best of the operations possible
            res = solve(a, b+1);
            res = min(res, solve(a+1, b));
            res = min(res, solve(a+1, b+1));
            return res += 1;
        };

        return solve(0, 0);
    }
};