class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res;
        unordered_map<int, int> m;

        for (int i = 0; i < n; i++) {
            int val = target - nums[i];
            if (m.count(val)) {
                res = {i, m[val]};
                break;
            }
            m[nums[i]] = i;
        }
        
        return res;
    }
};
