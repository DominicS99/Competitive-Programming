class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int l = 0, r = nums[0]+1;
        while (l < r) {
            int x = l + (r-l)/2;

            int curr = 0;
            for (int &y : nums) {
                if (y < x) break;
                curr++;
            }
            if (curr == x) return x;

            if (curr > x) {
                l = x+1;
            } else {
                r = x;
            }
        }
        return -1;
    }
};
