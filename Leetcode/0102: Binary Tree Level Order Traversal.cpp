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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            queue<TreeNode *> newQ;
            vector<int> level;
            while (!q.empty()) {
                auto curr = q.front(); q.pop();
                if (!curr) continue;
                level.push_back(curr->val);
                newQ.push(curr->left);
                newQ.push(curr->right);
            }
            if (!level.empty()) res.push_back(level);
            swap(q, newQ);
        }

        return res;
    }
};