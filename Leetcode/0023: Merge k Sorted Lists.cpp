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
 

/*
  3 solutions:
    1) PQ: Good on time, ok on memory. Could be improved with storing ListNode* rather than pii
    2) Brute force: Nearly TLE, ok on memory, only works because of relatively low input sizes.
    3) Vector sort: Ok on time, terrible on memory. Probably the easiest to implement though.
*/


// 1)
typedef pair<int, int> pii;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for (int i = 0; i < k; i++) {
            if (!lists[i]) continue;
            pq.emplace(lists[i]->val, i);
        }

        ListNode * root = new ListNode();
        auto curr = root;
        while (!pq.empty()) {
            auto [num, i] = pq.top(); pq.pop(); 
            curr->next = new ListNode(num);
            curr = curr->next;
            lists[i] = lists[i]->next;
            if (lists[i]) pq.emplace(lists[i]->val, i);
        }

        return root->next;
    }
};

// 2)

// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         int k = lists.size();
//         ListNode * root = new ListNode();
//         auto curr = root;
//         while (1) {
//             int lowInd = k, lowVal = 1e9;
//             for (int i = 0; i < k; i++) {
//                 if (!lists[i]) continue;
//                 if (lowVal > lists[i]->val) {
//                     lowInd = i;
//                     lowVal = lists[i]->val;
//                 }
//             }
//             if (lowInd == k) break;
//             curr->next = new ListNode(lowVal);
//             curr = curr->next;
//             lists[lowInd] = lists[lowInd]->next;
//         }

//         return root->next;
//     }
// };

// 3)

// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         int k = lists.size();
//         vector<int> d(500*k, 1e9);
//         int l = 0;
//         for (int i = 0; i < k; i++) {
//             for (ListNode * curr = lists[i]; curr; curr = curr->next) {
//                 d[l] = curr->val;
//                 l++;
//             }
//         }
//         sort(d.begin(), d.end());

//         ListNode * root = new ListNode();
//         auto curr = root;
//         for (int i = 0; i < l; i++) {
//             curr->next = new ListNode();
//             curr = curr->next;
//             curr->val = d[i];
//         }

//         return root->next;
//     }
// };
