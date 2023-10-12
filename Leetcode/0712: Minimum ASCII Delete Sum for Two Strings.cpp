class Solution {
public:
    void getSum(string &s, vector<int> &sum) {
        for (int i = s.length()-1; i >= 0; i--) {
            sum[i] += s[i] + sum[i+1];
        }
    }

    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        int memo[m+1][n+1];
        memset(memo, -1, sizeof(memo));
        vector<int> s1Sum(m+1, 0), s2Sum(n+1, 0);
        getSum(s1, s1Sum); getSum(s2, s2Sum);

        function<int(int, int)> solve = [&] (int a, int b) {
            auto &res = memo[a][b];
            if (res != -1) return res;
            if (a == m) return res = s2Sum[b];
            if (b == n) return res = s1Sum[a];
            if (s1[a] == s2[b]) return res = solve(a+1, b+1);

            return res = min(solve(a, b+1) + s2[b], solve(a+1, b) + s1[a]);
        };

        return solve(0, 0);
    }
};