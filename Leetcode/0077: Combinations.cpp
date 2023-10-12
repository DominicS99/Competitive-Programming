class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;

        function<void(int)> solve = [&] (int l) {
            if (curr.size() == k) {res.push_back(curr); return;}
            if (l > n) return;

            for (int i = l; i <= n; i++) {
                curr.push_back(i);
                solve(i+1);
                curr.pop_back();
            }
        };

        solve(1);
        return res;
    }
};