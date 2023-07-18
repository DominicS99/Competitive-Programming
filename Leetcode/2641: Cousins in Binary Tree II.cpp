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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return root;
        vector<int> level;

        queue<TreeNode *> q;
        q.push(root);

        int i = 0;
        while (!q.empty()) {
            queue<TreeNode *> newQ;
            int total = 0;
            while (!q.empty()) {
                TreeNode * curr = q.front(); q.pop();
                if (!curr) continue;
                total += curr->val;
                newQ.push(curr->left);
                newQ.push(curr->right);
            }
            swap(q, newQ);
            level.push_back(total);
        }

        q.push(root);
        root->val = 0;
        i = 1;
        while (!q.empty()) {
            queue<TreeNode *> newQ;
            while (!q.empty()) {
                TreeNode * curr = q.front(); q.pop();
                if (!curr) continue;

                int exclude = curr->left ? curr->left->val : 0;
                exclude += curr->right ? curr->right->val : 0;

                if (curr->left) curr->left->val = level[i] - exclude;
                if (curr->right) curr->right->val = level[i] - exclude;

                newQ.push(curr->left);
                newQ.push(curr->right);
            }
            swap(q, newQ);
            i++;
        }

        return root;
    }
};
