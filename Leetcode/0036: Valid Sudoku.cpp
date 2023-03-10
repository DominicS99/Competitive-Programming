class Solution {
public:
    bool subBox(vector<vector<char>> &board, int a, int b) {
        unordered_set<char> group;
        for (int i = a; i < a+3; i++) {
            for (int j = b; j < b+3; j++) {
                if (board[i][j] == '.') continue;
                if (group.count(board[i][j])) return false;
                group.insert(board[i][j]);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> group;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                if (group.count(board[i][j])) return false;
                group.insert(board[i][j]);
            }
        }

        for (int j = 0; j < 9; j++) {
            unordered_set<char> group;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.') continue;
                if (group.count(board[i][j])) return false;
                group.insert(board[i][j]);
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (!subBox(board, i*3, j*3)) return false;
            }
        }

        return true;
    }
};
