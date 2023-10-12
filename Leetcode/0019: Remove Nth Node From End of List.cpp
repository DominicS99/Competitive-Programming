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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *l = head, *r = head;
        for (int i = 0; i < n && r; i++) r = r->next;
        if (!r) return head->next;

        for (; r->next; r = r->next) l = l->next;
        l->next = (l->next ? l->next->next : NULL);

        return head;
    }
};