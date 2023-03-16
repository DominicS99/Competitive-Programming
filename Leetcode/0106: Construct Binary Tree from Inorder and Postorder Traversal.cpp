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

// Improved solution, only change is storing the inorder information in a hashmap instead of narrowing the iterative window
class Solution {
int __PI;
unordered_map<int, int> m;

public:
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int left, int right) {
        if (left == right) return nullptr;

        int mid = postorder[__PI--];
        TreeNode *root = new TreeNode(mid);

        root->right = solve(inorder, postorder, m[mid]+1, right);
        root->left = solve(inorder, postorder, left, m[mid]);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        __PI = postorder.size()-1;
        int n = inorder.size();
        for (int i = 0; i < n; i++) m[inorder[i]] = i;

        return solve(inorder, postorder, 0, n);
    }
};


/*
// First solution
class Solution {

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int left = 0, int right = -1) {
        if (right == -1) right = inorder.size();
        if (left == right) return nullptr;
        
        TreeNode * root = new TreeNode(postorder.back());
        postorder.pop_back();

        int mid = left;
        while (mid < right) {
            if (inorder[mid] == root->val) break;
            mid++;
        }

        root->right = buildTree(inorder, postorder, mid+1, right);
        root->left = buildTree(inorder, postorder, left, mid);
        return root;
    }
};
*/
