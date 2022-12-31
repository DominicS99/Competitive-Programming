// Fairly standard prefix-sum

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size() + 1;
        int n = matrix[0].size() + 1;
        sums = vector<vector<int>>(m, vector<int>(n, 0));

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                sums[i][j] = sums[i][j-1] + sums[i-1][j] + matrix[i-1][j-1] - sums[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1] + sums[row1][col1] - sums[row2+1][col1] - sums[row1][col2+1];
    }

private:
    vector<vector<int>> sums;
};
