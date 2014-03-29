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
    ListNode *rotateRight(ListNode *head, int k) {
        if ( !head ) return head;
        int n = 0;
        for (ListNode *l = head; l; l = l->next) ++n;
        if ( n == 0 || (k %= n) == 0 ) return head;
        n -= k;
        ListNode *t, *p;
        for (t = head; --n > 0; t = t->next);
        for (p = t; p->next; p = p->next);
        p->next = head;
        head = t->next;
        t->next = nullptr;
        return head;
    }
};
