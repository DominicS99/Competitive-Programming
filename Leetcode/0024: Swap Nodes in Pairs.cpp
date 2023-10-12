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
    ListNode* swapPairs(ListNode* head) {
        for (ListNode *l = head, *r, *prev = head; l && l->next; prev = l, l = l->next) {
            r = l->next;
            l->next = r->next;
            r->next = l;

            if (prev == head) head = r;
            else prev->next = r;
        }
        return head;
    }
};