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
    ListNode *insertionSortList(ListNode *head) {
        if ( !head || !head->next ) return head;
        ListNode **h = &head;
        for (ListNode **l = &head->next; *l;) {
            ListNode **r = h;
            while ( (*r)->val < (*l)->val ) r = &(*r)->next;
            if ( *r != *l ) {
                ListNode *p = *l;
                *l = p->next;
                p->next = *r;
                *r = p;
            } else {
                l = &(*l)->next;
            }
        }
        return *h;
    }
};
