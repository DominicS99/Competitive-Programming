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
    unordered_map<int, int> m;
    int high = -1;

    void traverse(TreeNode* root) {
        if (!root) return;
        high = max(high, ++m[root->val]);
        traverse(root->left);
        traverse(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        traverse(root);
        for (auto &[x, c] : m) {
            if (c == high) res.push_back(x);
        }
        return res;
    }
};