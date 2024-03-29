class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> s;
        for (auto &it : nums) s.insert(it);
        while (s.count(original)) original *= 2;
        return original;
    }
};
