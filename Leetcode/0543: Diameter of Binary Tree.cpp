/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

typedef pair<int, int> pii;
class Solution {
public:
    pii solve(TreeNode * curr) {
        if (!curr) return {0, 0};

        auto [ld, lh] = solve(curr->left);
        auto [rd, rh] = solve(curr->right);

        int diam = max({ld, rd, lh+rh});
        int height = max(lh, rh) + 1;

        return {diam, height};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).first;
    }
};
