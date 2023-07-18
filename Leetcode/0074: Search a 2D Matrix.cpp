class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int l = 0, r = matrix.size(), row = -1;
        while (l < r) {
            int m = l + (r-l)/2;

            if (matrix[m][0] > target) {
                r = m;
            } else if (matrix[m][n-1] < target) {
                l = m+1;
            } else {
                row = m;
                break;
            }
        }

        if (row == -1) return false;

        l = 0, r = n;
        while (l < r) {
            int m = l + (r-l)/2;

            if (matrix[row][m] == target) {
                return true;
            } else if (matrix[row][m] > target) {
                r = m;
            } else {
                l = m+1;
            }
        }

        return false;
    }
};
