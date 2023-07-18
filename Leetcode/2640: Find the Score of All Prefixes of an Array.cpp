typedef long long LL;
class Solution {
public:
    vector<LL> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        LL high = nums[0];
        vector<LL> res(n);
        res[0] = high * 2;

        for (int i = 1; i < n; i++) {
            high = max(high, (LL)nums[i]);
            res[i] = nums[i] + high + res[i-1];
        }
        return res;
    }
};
