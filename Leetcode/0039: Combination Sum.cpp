class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> res;
        vector<int> curr;

        function<void(int, int)> dfs = [&] (int l, int sum) {
            if (sum == target) {
                res.emplace_back(curr);
                return;
            }
            for (int r = l; r < n; r++) {
                int next = sum + candidates[r];
                if (next > target) continue;
                curr.push_back(candidates[r]);
                dfs(r, next);
                curr.pop_back();
            }
        };
        dfs(0, 0);

        return res;
    }
};
