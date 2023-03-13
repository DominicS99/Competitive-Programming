/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* solve(ListNode** head, int l, int r) {
        if (!head || l == r) return nullptr;

        int mid = l + (r-l)/2;
        auto root = new TreeNode();

        root->left = solve(head, l, mid);
        root->val = (*head)->val;
        *head = (*head)->next;
        root->right = solve(head, mid+1, r);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int size = 0;
        for (auto curr = head; curr; curr = curr->next) size++;
        return solve(&head, 0, size);
    }
};
