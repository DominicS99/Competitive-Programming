typedef long long ll;
class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();
        ll memo[n+1][3];
        memset(memo, -1, sizeof(memo));
        function<ll(int, int)> solve = [&] (int i, int x) {
            auto &res = memo[i][x];
            if (res != -1) return res;
            if (i == n) return res = 0;
            if (x == 2) return res = solve(i+1, 0) + max(0, k-nums[i]);
            
            if (nums[i] >= k) {
                res = solve(i+1, 0);
            } else {
                res = solve(i+1, x+1);
            }
            return res = min(res, solve(i+1, 0) + max(0, k-nums[i]));
        };
    
        return solve(0, 0);
    }
};