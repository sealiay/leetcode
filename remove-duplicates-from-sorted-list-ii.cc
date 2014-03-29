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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *h = head, **p = &h;
        for (ListNode *l = head; l;) {
            if ( l->next && l->val == l->next->val ) {
                int v = l->val;
                for (l = l->next->next; l && l->val == v; l = l->next);
            } else {
                *p = l;
                p = &l->next;
                l = l->next;
            }
        }
        *p = nullptr;
        return h;
    }
    
};
