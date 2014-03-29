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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *h, **p = &h;
        while ( l1 && l2 ) {
            ListNode **q;
            if ( l1->val < l2->val ) q = &l1;
            else q = &l2;
            *p = *q;
            *q = (*q)->next;
            p = &(*p)->next;
        }
        while ( l1 ) {
            *p = l1;
            l1 = l1->next;
            p = &(*p)->next;
        }
        while ( l2 ) {
            *p = l2;
            l2 = l2->next;
            p = &(*p)->next;
        }
        *p = nullptr;
        return h;
    }
};
