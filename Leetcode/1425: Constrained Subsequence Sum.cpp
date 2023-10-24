class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size(), check = -1e9;
        map<int, int> m;
        vector<int> memo(n, 0);
        m[0]++;
        for (int i = 0; i < n; i++) {
            check = max(check, nums[i]);
            memo[i] = max(memo[i], m.rbegin()->first + nums[i]);
            if (i >= k) {
                if (--m[memo[i-k]] < 1) m.erase(memo[i-k]);
            }
            m[memo[i]]++;
        }
        if (check < 0) return check;
        return *max_element(memo.begin(), memo.end());
    }
};