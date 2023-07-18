typedef long long LL;
class Solution {
public:
    vector<LL> distance(vector<int>& nums) {
        int n = nums.size();
        vector<LL> res(n);
        unordered_map<LL, vector<LL>> m;
        for (int i = 0; i < n; i++) {
            m[nums[i]].push_back(i);
        }

        for (auto &[val, group] : m) {
            LL left = 0;
            LL right = accumulate(group.begin(), group.end(), (LL)0);
            for (int i = 0, r = group.size(); i < group.size(); i++, r--) {
                LL curr = group[i];
                res[curr] = right - (r * curr) + (i * curr) - left;

                left += curr;
                right -= curr;
            }
        }
        return res;
    }
};
