/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool check(vector<vector<int>> &grid, int num, int x, int y, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (num != grid[i+x][j+y]) return false;
            }
        }
        return true;
    }

    Node* solve(vector<vector<int>>& grid, int x, int y, int m) {
        int n = m/2;
        vector<int> dirX = {0, 0, n, n};
        vector<int> dirY = {0, n, 0, n};

        Node * curr = new Node(grid[x][y], true);
        bool f = true;
        int gNum = grid[x][y];
        vector<Node *> d(4);
        for (int i = 0; i < 4; i++) {
            int r = x + dirX[i];
            int c = y + dirY[i];

            if (check(grid, grid[r][c], r, c, n)) {
                d[i] = new Node(grid[r][c], true);
                if (gNum != grid[r][c]) f = false;
            } else {
                f = false;
                d[i] = solve(grid, r, c, n);
            }
        }

        if (!f) {
            curr->isLeaf = false;
            curr->topLeft = d[0];
            curr->topRight = d[1];
            curr->bottomLeft = d[2];
            curr->bottomRight = d[3];
        }

        return curr;
    }

    Node* construct(vector<vector<int>>& grid) {
        int m = grid.size();
        return solve(grid, 0, 0, m);
    }
};