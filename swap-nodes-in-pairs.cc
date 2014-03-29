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
    ListNode *swapPairs(ListNode *head) {
        for (ListNode **l = &head; *l && (*l)->next; l = &(*l)->next->next) {
            ListNode *a = *l;
            ListNode *b = a->next;
            ListNode *c = a->next->next;
            *l = b;
            b->next = a;
            a->next = c;
        }
        return head;
    }
};
