class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        int low = nums[0];
        set<int> order;
        map<int, int> freq;
        for (int i = 2; i < n; i++) {
            order.insert(nums[i]);
            freq[nums[i]]++;
        }

        for (int i = 1; i+1 < n; i++) {
            low = min(low, nums[i-1]);
            auto it = order.lower_bound(nums[i]-1);
            if (low < nums[i] && low < *it && nums[i] > *it) return true;

            if (--freq[nums[i+1]] == 0) order.erase(*it);
        }

        return false;
    }
};