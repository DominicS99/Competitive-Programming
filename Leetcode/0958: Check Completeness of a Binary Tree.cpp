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
class Solution {
public:
    int count(TreeNode * root) {
        if (!root) return 0;
        return count(root->left) + count(root->right) + 1;
    }

    bool traverse(TreeNode * root, int index, int size) {
        if (!root) return true;
        if (index > size) return false;
        return traverse(root->left, index*2, size) && traverse(root->right, index*2 + 1, size);
    }

    bool isCompleteTree(TreeNode* root) {
        return traverse(root, 1, count(root));
    }
};
