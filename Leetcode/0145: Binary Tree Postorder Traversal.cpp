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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;

        function <void (TreeNode*)> traverse = [&] (TreeNode* curr) {
            if (!curr) return;
            traverse(curr->left);
            traverse(curr->right);
            res.push_back(curr->val);
        };

        traverse(root);
        return res;
    }
};
