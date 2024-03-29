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
    vector<TreeNode*> solve(int l, int r) {
        vector<TreeNode*> res;
        if (l > r) {
            res.push_back(NULL);
            return res;
        }

        for (int i = l; i <= r; i++) {
            auto left = solve(l, i-1);
            auto right = solve(i+1, r);

            for (auto &x : left) {
                for (auto &y : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = x;
                    root->right = y;
                    res.push_back(root);
                }
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};