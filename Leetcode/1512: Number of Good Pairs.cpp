class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto &x : nums) {
            m[x]++;
        }

        int res = 0;
        for (auto &[val, freq] : m) {
            res += (freq-1)*freq/2;
        }
        return res;
    }
};
