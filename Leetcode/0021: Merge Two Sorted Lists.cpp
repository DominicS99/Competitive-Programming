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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> a1, a2, res;
        while (list1) {
            a1.push_back(list1->val);
            list1 = list1->next;
        }

        while (list2) {
            a2.push_back(list2->val);
            list2 = list2->next;
        }

        int l = 0, r = 0;
        while (l < a1.size() && r < a2.size()) {
            if (a1[l] < a2[r]) {
                res.push_back(a1[l]);
                l++;
            } else {
                res.push_back(a2[r]);
                r++;
            }
        }

        while (l < a1.size()) {
            res.push_back(a1[l]);
            l++;
        }
        while (r < a2.size()) {
            res.push_back(a2[r]);
            r++;
        }

        if (res.empty()) return nullptr;

        ListNode * root = new ListNode(res[0]);
        ListNode * prev = root;
        for (int i = 1; i < res.size(); i++) {
            ListNode * curr = new ListNode(res[i]);
            prev->next = curr;
            prev = curr;
        }

        return root;
    }
};
