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
    map<pair<TreeNode*, bool>, int> memo;

    int solve(TreeNode* root, bool canRob) {
        if (!root) return 0;
        if (memo.count({root, canRob})) return memo[{root, canRob}];

        auto &res = memo[{root, canRob}];
        res = solve(root->left, 1) + solve(root->right, 1);
        if (canRob) res = max(res, solve(root->left, 0) + solve(root->right, 0) + root->val);
        return res;
    }

    int rob(TreeNode* root) {
        return max(solve(root, 1), solve(root, 0));
    }
};