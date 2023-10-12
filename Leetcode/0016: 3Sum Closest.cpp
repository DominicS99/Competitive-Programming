class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 1e9, close = 1e9;
        for (int i = 0; i < n; i++) {
            int l = i+1, r = n-1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                int check = abs(sum - target);
                if (check < close) {
                    if (check == 0) return sum;
                    close = check;
                    res = sum;
                }

                if (sum < target) l++;
                else r--;
            }

        }
        return res;
    }
};