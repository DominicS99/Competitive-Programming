class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        vector<vector<int>> res;
        vector<int> curr;

        function<void(int, int)> dfs = [&] (int l, int sum) {
            if (sum == target) {
                res.emplace_back(curr);
                return;
            }
            for (int r = l; r < n; r++) {
                if (r != l && candidates[r] == candidates[r-1]) continue;
                int next = candidates[r]+sum;
                if (next > target) continue;
                curr.push_back(candidates[r]);
                dfs(r+1, next);
                curr.pop_back();
            }
        };
        dfs(0, 0);

        return res;
    }
};