class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> nums, res;
        int k = 0;
        for (auto &s : words) {
            if (s != "prev") {
                k = 0;
                nums.push_back(stoi(s));
            } else {
                if (++k > nums.size()) {
                    res.push_back(-1);
                } else {
                    res.push_back(nums[nums.size()-k]);
                }
            }
        }
        return res;
    }
};