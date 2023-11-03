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
    int res;

    pii solve(TreeNode *root) {
        if (!root) return {0, 0};
        auto [sumA, countA] = solve(root->left);
        auto [sumB, countB] = solve(root->right);
        int sum = sumA+sumB+root->val;
        int count = countA+countB+1;
        if (root->val == sum/count) res++;
        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        res = 0;
        solve(root);
        return res;
    }
};