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
    ListNode *sortList(ListNode *head) {
        for (int i = 1; st(i, &head); i *= 2);
        return head;
    }
    
    bool st(int s, ListNode **head) {
        ListNode **h = head;
        while ( *h ) {
            ListNode *l = *h, *t;
            for (int i = 1; i < s && l; ++i) l = l->next;
            if ( !l || !l->next ) break;
            t = l;
            for (int i = 0; i < s && t->next; ++i) t = t->next;
            h = sp(s, h, l, t);
        }
        return h != head;
    }
    
    ListNode **sp(size_t s, ListNode **h, ListNode *l, ListNode *t) {
        ListNode *l1 = *h;
        ListNode *l2 = l->next;
        ListNode *n = t->next;
        l->next = t->next = nullptr;
        *h = mg(s, l1, l2);
        for (t = *h; t->next; t = t->next);
        t->next = n;
        return &t->next;
    }
    
    ListNode *mg(size_t s, ListNode *l1, ListNode *l2) {
        ListNode *head, **h = &head;
        while ( l1 && l2 ) {
            if ( l1->val < l2->val ) {
                *h = l1;
                h = &(*h)->next;
                l1 = l1->next;
            } else {
                *h = l2;
                h = &(*h)->next;
                l2 = l2->next;
            }
        }
        while ( l1 ) {
            *h = l1;
            h = &(*h)->next;
            l1 = l1->next;
        }
        while ( l2 ) {
            *h = l2;
            h = &(*h)->next;
            l2 = l2->next;
        }
        *h = nullptr;
        return head;
    }
};
