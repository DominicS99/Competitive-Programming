class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int low = n/3;
        unordered_map<int, int> m;
        for (auto &x : nums) {
            m[x]++;
        }

        vector<int> res;
        for (auto &[val, freq] : m) {
            if (freq > low) res.push_back(val);
        }
        return res;
    }
};