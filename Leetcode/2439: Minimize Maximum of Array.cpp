typedef long long LL;

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        LL res = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            res = max(res, (LL)ceil(sum/(i+1.0)));
        }
        return res;
    }
};
