typedef long long ll;

class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int MOD = 1e9+7;
        int n = nums.size();
        vector<ll> dumb(n);
        for (int i = 0; i < n; i++) {
            dumb[i] = (ll)nums[i] + (s[i] == 'L' ? -d : d);
        }
        sort(dumb.begin(), dumb.end());
        ll res = 0, sum = 0, curr = 0;
        for (int i = 1; i < n; i++) {
            curr = (abs(dumb[i]-dumb[i-1])*i)%MOD;
            sum = (sum + curr)%MOD;
            res = (res + sum)%MOD;
        }
        return res;
    }
};