class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res(n);

        for (int j = 0; j < n; j++) {
            int curr = 0;
            for (int i = 0; i < m; i++) {
                int temp = to_string(grid[i][j]).length();
                curr = max(curr, temp);
            }
            res[j] = curr;
        }
        return res;
    }
};
