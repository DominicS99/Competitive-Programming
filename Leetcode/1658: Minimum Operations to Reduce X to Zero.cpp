typedef long long ll;
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int res = 1e9;

        ll tot = accumulate(nums.begin(), nums.end(), (ll)0);
        if (tot < x) return -1;

        ll sum = 0;
        int l = 0, r = 0;
        while (r < n) {
            if (tot - sum == x) {
                res = min(res, n-(r-l));
                sum -= nums[l++];
                sum += nums[r++];
            } else if (tot - sum < x) {
                sum -= nums[l++];
            } else {
                sum += nums[r++];
            }
        }
        
        while (l < n && tot - sum < x) sum -= nums[l++];
        if (tot - sum == x) res = min(res, n-(r-l));

        return res == 1e9 ? -1 : res;
    }
};