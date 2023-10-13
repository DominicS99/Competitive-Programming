class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int memo[m+1][n+1];
        memset(memo, -1, sizeof(memo));

        int low = -1e9;

        function<int(int, int)> solve = [&] (int a, int b) {
            auto &res = memo[a][b];
            if (res != -1) return res;
            if (a == m || b == n) return res = 0;

            res = solve(a+1, b+1) + (nums1[a] * nums2[b]);
            low = max(low, nums1[a] * nums2[b]);
            res = max(res, solve(a+1, b));
            res = max(res, solve(a, b+1));
            return res;
        };

        int res = solve(0, 0);
        if (low < 0) return low;
        return res;
    }
};