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
    TreeNode* bstHelp(vector<int> & nums, int l, int r) {
        if (l == r) return nullptr;
        int m = l + (r-l)/2;
        TreeNode* curr = new TreeNode(nums[m], bstHelp(nums, l, m), bstHelp(nums, m+1, r));
        return curr;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bstHelp(nums, 0, nums.size());
    }
};
