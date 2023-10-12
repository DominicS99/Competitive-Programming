class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int a = 0, b = -1, x = -1, y = n;
        for (int i = 0; i+1 < n; i++) {
            if (nums[i] > nums[i+1]) {
                b = i+1;
                x = i+1;
                break;
            }
        }

        auto solve = [&] (int l, int r) {
            while (l < r) {
                int m = l + (r-l)/2;
                if (nums[m] == target) return true;

                if (nums[m] > target) {
                    r = m;
                } else {
                    l = m+1;
                }
            }
            return false;
        };

        if (b == -1) return solve(a, y);
        
        if (solve(a, b)) return true;
        return solve(x, y);
    }
};