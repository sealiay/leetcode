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
    ListNode *detectCycle(ListNode *head) {
        if ( !head || !head->next ) return nullptr;
        for (ListNode *p = head->next, *q = p->next; q && q->next; p = p->next, q = q->next->next) {
            if ( p == q ) {
                for (p = head; p != q; p = p->next, q = q->next);
                return p;
            }
        }
        return nullptr;
    }
};
