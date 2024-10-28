typedef long long ll;
ll MOD = 1e9+7;

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        ll memo[n+1][201][201];
        memset(memo, -1, sizeof(memo));
        function<int(int, int, int)> solve = [&] (int i, int a, int b) {
            auto &res = memo[i][a][b];
            if (res != -1) return res;
            if (i == n) return res = ((a == b) && a);

            res = solve(i+1, a, b);
            res = (res + solve(i+1, (!a ? nums[i] : gcd(a, nums[i])), b))%MOD;
            res = (res + solve(i+1, a, (!b ? nums[i] : gcd(nums[i], b))))%MOD;
            return res;
        };

        return solve(0, 0, 0);
    }
};
