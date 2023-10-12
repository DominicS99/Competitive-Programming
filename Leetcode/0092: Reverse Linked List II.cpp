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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode *curr = head, *prev = NULL;
        int i = 1;
        for (; i < left; i++, curr = curr->next) prev = curr;

        ListNode *tempHead = curr;
        for (ListNode *nxt = curr->next; i < right; i++, nxt = curr->next) {
            curr->next = nxt->next;
            nxt->next = tempHead;
            tempHead = nxt;
        }

        if (!prev) return tempHead;
        prev->next = tempHead;
        return head;
    }
};