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
    ListNode* partition(ListNode* head, int x) {
        ListNode *lHead = NULL, *rHead = NULL, *lCurr = NULL, *rCurr = NULL;
        for (ListNode *curr = head; curr; curr = curr->next) {
            if (curr->val < x) {
                if (!lHead) {
                    lHead = curr;
                    lCurr = lHead;
                } else {
                    lCurr->next = curr;
                    lCurr = lCurr->next;
                }
            } else {
                if (!rHead) {
                    rHead = curr;
                    rCurr = rHead;
                } else {
                    rCurr->next = curr;
                    rCurr = rCurr->next;
                }
            }
        }
        if (lCurr) lCurr->next = rHead;
        if (rCurr) rCurr->next = NULL;
        if (!lCurr && rCurr) return rHead;
        return lHead;
    }
};