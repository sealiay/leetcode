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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if ( k < 2 || !head || !head->next ) return head;
        for (ListNode **l = &head; l && *l; l = rv(l, k - 1));
        return head;
    }
    
    ListNode **rv(ListNode **h, int k) {
        int n = 0;
        ListNode *t;
        for (t = *h; t && n < k; t = t->next) ++n;
        if ( !t ) return nullptr;
        ListNode *a = *h, *b = a->next, *d = a;
        *h = t;
        a->next = t->next;
        while ( a != t ) {
            ListNode *c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        return &d->next;
    }
};
