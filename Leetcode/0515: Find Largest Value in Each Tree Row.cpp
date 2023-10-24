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
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int num = q.front()->val;
            queue<TreeNode*> newQ;
            while (!q.empty()) {
                auto curr = q.front(); q.pop();
                num = max(num, curr->val);
                if (curr->left) newQ.push(curr->left);
                if (curr->right) newQ.push(curr->right);
            }
            res.push_back(num);
            swap(q, newQ);
        }
        return res;
    }
};