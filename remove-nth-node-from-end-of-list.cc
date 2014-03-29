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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode o(0), c(0);
        o.next = head;
        ListNode *p = &o, *t = &o, *a = &c;
        
        while ( n-- > 0 ) {
            t = t->next;
        }
        while ( t->next ) {
            a->next = p->next;
            a = p->next;
            p = p->next;
            t = t->next;
        }
        p = p->next;
        while ( p->next ) {
            a->next = p->next;
            a = p->next;
            p = p->next;
        }
        a->next = NULL;
        return c.next;
    }
};
