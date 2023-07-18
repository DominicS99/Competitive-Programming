typedef long long LL;

class Solution {
public:
    vector<LL> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<LL> ps(n+1);
        ps[0] = 0;
        for (int i = 1; i <= n; i++) {
            ps[i] = nums[i-1] + ps[i-1];
        }

        vector<LL> res;
        for (auto &q : queries) {
            LL l = 0, r = n;
            while (l < r) {
                int m = l + (r-l)/2;
                if (nums[m] < q) {
                    l = m+1;
                } else {
                    r = m;
                }
            }
            res.push_back(q*l - ps[l] + (ps[n]-ps[l]) - (q*(n-l)));
        }
        return res;
    }
};
