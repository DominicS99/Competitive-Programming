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
    bool solve(TreeNode* root, TreeNode* low, TreeNode* high) {
        if (!root) return true;
        
        if (low && root->val <= low->val) return false;
        if (high && root->val >= high->val) return false;

        return solve(root->left, low, root) && solve(root->right, root, high);
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, NULL, NULL);
    }
};