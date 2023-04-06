class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int, int> m;
        for (auto &it : nums) m[it]++;
        while (1) {
            vector<int> curr;
            for (auto &it : m) {
                if (it.second == 0) continue;
                curr.push_back(it.first);
                (it.second)--;
            }
            if (curr.empty()) break;
            res.push_back(curr);
        }
        return res;
    }
};
