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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        n -= m;
        if ( n < 1 ) return head;
        ListNode **h = &head;
        while ( --m > 0 ) h = &(*h)->next;
        ListNode *l = *h, *p = l->next;
        while ( --n >= 0 ) {
          ListNode *q = p->next;
          p->next = l;
          l = p;
          p = q;
        }
        (*h)->next = p;
        *h = l;
        return head;
    }
};
