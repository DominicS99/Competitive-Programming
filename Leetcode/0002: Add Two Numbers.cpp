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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, bool carry = 0) {
        if (!l1 && !l2 && !carry) return nullptr;
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        carry = (sum > 9);
        sum %= 10;

        ListNode * curr = new ListNode(sum, addTwoNumbers((l1 ? l1->next : l1), (l2 ? l2->next : l2), carry));
        return curr;
    }
};
