// Updated solution: Same idea, just using less space. For even better memory, the grid only needs to 
//    be min(s.length(), numRows), but constraint is 1e3 so I didn't think it was necessary.
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        int i = 0; bool f = true;
        vector<string> grid(numRows);
        for (char c : s) {
            grid[i] += c;
            f ? i++ : i--;
            if (i == numRows-1 || !i) f = !f;
        }

        string res;
        for (auto &row : grid) res += row;
        return res;
    }
};

/*
// First solution
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        int n = s.length();
        vector<vector<char>> grid(numRows, vector<char>(n, '0'));

        int i = 0; bool f = true;
        for (int j = 0; j < n; j++) {
            grid[i][j] = s[j];
            f ? i++ : i--;
            if (i == numRows-1 || !i) f = !f;
        }

        string res;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') continue;
                res += grid[i][j];
            }
        }

        return res;
    }
};
*/
