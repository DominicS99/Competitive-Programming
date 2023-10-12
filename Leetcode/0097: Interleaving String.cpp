class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();
        int memo[m+1][n+1];
        memset(memo, -1, sizeof(memo));

        function<int(int, int)> solve = [&] (int a, int b) {
            auto &res = memo[a][b];
            if (res != -1) return res;
            if (a == m) return res = (s2.substr(b) == s3.substr(a+b));
            if (b == n) return res = (s1.substr(a) == s3.substr(a+b));

            res = false;
            if (s1[a] == s3[a+b]) res |= solve(a+1, b);
            if (s2[b] == s3[a+b]) res |= solve(a, b+1);
            return res;
        };

        return solve(0, 0);
    }
};