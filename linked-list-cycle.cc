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
    bool hasCycle(ListNode *head) {
        if ( !head || !head->next) return false;
        for (ListNode *p = head->next->next, *q = head->next; p && p->next; p = p->next->next, q = q->next) {
            if ( p == q ) return true;
        }
        return false;
    }
};
