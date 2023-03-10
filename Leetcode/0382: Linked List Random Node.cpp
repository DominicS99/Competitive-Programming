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
ListNode* root;

public:
    Solution(ListNode* head) {
        root = head;
    }
    
    int getRandom() {
        int res = 0, x = 1;
        for (auto curr = root; curr; curr = curr->next) {
            if (!(rand()%x)) res = curr->val;
            x++;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
