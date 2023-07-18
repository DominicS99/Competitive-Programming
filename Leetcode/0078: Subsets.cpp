class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int lim = 1<<n;
        vector<vector<int>> res;
        for (int i = 0; i < lim; i++) {
            vector<int> curr;
            for (int j = 0; j < n; j++) {
                if (i & (1<<j)) curr.push_back(nums[j]);
            }
            res.push_back(curr);
        }
        return res;
    }
};
