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
    ListNode *partition(ListNode *head, int x) {
        ListNode *la = nullptr, *lb = nullptr, **ea = &la, **eb = &lb;
        for (ListNode *l = head; l; l = l->next) {
            if ( l->val < x ) {
                *ea = l;
                ea = &l->next;
            } else {
                *eb = l;
                eb = &l->next;
            }
        }
        *ea = lb;
        *eb = nullptr;
        return la;
    }
};
