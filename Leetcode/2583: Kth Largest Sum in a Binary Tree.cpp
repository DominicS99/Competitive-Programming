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
    int depth(TreeNode* root) {
        if (!root) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        int levels = depth(root);
        if (levels < k) return -1;

        vector<long long> sums(levels, 0);
        function <void (TreeNode*, int)> solve = [&] (TreeNode * curr, int level) {
            if (!curr) return;
            sums[level] += curr->val;
            solve(curr->left, level+1);
            solve(curr->right, level+1);
        };
        solve(root, 0);

        sort(sums.rbegin(), sums.rend());
        return sums[k-1];
    }
};
