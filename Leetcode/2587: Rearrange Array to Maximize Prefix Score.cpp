typedef long long int LL;

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        sort(nums.rbegin(), nums.rend());
        if (nums[0] <= 0) return 0;
        int i;
        LL val = nums[0];
        for (i = 1; i < n; i++) {
            val += nums[i];
            if (val > 0) continue;
            break;
        }

        return i;
    }
};
