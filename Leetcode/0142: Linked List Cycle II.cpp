/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *h) {
        // Marking vals as visited (1e9 aka high number that isn't possible)
        // If h == visited or NULL, we are done
        if (h) {
            do {
                h->val = 1e9;
                h = h->next;
            } while (h && h->val != 1e9);
        }
        return h;
    }
};
