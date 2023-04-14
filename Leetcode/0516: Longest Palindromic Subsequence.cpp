class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> memo(n+1, vector<int>(n+1, -1));

        function<int(int, int)> solve = [&] (int l, int r) {
            int &curr = memo[l][r];
            if (curr > -1) return curr;
            if (l > r) return curr = 0;
            if (l == r) return curr = 1;

            if (s[l] == s[r]) {
                curr = solve(l+1, r-1) + 2;
            } else {
                curr = max(solve(l+1, r), solve(l, r-1));
            }
            return curr;
        };

        return solve(0, n-1);
    }
};
