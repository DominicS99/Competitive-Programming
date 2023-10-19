class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        for (auto &x : nums) {
            if (s.count(x)) s.erase(x);
            else s.insert(x);
        }
        vector<int> res;
        for (auto &x : s) res.push_back(x);
        return res;
    }
};