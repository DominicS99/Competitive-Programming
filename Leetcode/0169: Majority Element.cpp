class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size()/2;
        unordered_map<int, int> m;
        for (auto &it : nums) m[it]++;
        for (auto &it : m) {
            if (it.second > n) return it.first; 
        }
        return -1;
    }
};
