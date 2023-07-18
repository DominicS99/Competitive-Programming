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
    int res = 0;
    pii solve(TreeNode* curr) {
        if (!curr) return {-1, -1};
        auto [sameL, changeR] = solve(curr->left);
        auto [changeL, sameR] = solve(curr->right);
        res = max({res, changeL+1, changeR+1});
        return {changeR+1, changeL+1};
    }

    int longestZigZag(TreeNode* root) {
        solve(root);
        return res;
    }
};
