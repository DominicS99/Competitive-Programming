/*
  Someday I will quickly realize that a problem like this uses binary search
*/

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int l = 0, r = nums.back()-nums[0];
        while (l < r) {
            int m = l + (r-l)/2;
            
            int curr = 0;
            for (int i = 1; i < n; i++) {
                if (nums[i]-nums[i-1] <= m) {
                    curr++;
                    i++;
                }
            }

            if (curr >= p) {
                r = m;
            } else {
                l = m+1;
            }
        }
        
        return l;
    }
};
