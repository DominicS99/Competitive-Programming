class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int res = 0, resi = 0;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (auto &it : mat[i]) {
                if (it == 1) count++;
            }
            if (res < count) {
                res = count;
                resi = i;
            }
        }
        return {resi, res};
    }
};
