class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                unordered_set<int> s;
                for (int k = i; k <= j; k++) {
                    s.insert(nums[k]);
                }
                res += s.size() * s.size();
            }
        }
        return res;
    }
};