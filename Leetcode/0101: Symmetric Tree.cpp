class Solution {
public:
    bool solve(TreeNode* one, TreeNode* two) {
        if (!one || !two) return one == two;
        return (one->val == two->val) && solve(one->left, two->right) && solve(one->right, two->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return solve(root, root);
    }
};
