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
    void reorderList(ListNode *head) {
        int n = 0;
        for (ListNode *l = head; l; l = l->next) ++n;
        if ( n <= 2 ) return;
        n = (n+1)/2;
        
        ListNode *t = head, *l1 = head, *l2;
        for (int i = 1; i < n; ++i) t = t->next;
        
        l2 = t->next;
        t->next = nullptr;
        l2 = rv(l2);
        while ( l2 ) {
            ListNode *a = l1->next, *b = l2->next;
            l1->next = l2;
            l2->next = a;
            l1 = a;
            l2 = b;
        }
    }
    
    ListNode *rv(ListNode *c) {
        ListNode *p = nullptr, *n;
        while ( c ) {
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        return p;
    }
};
