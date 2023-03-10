typedef long long LL;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        LL l = 0, r = accumulate(nums.begin(), nums.end(), 0);

        for (int i = 0; i < n; i++) {
            r -= nums[i];
            if (l == r) return i;
            l += nums[i];
        }

        return -1;
    }
};
