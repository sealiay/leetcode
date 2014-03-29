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
    ListNode *deleteDuplicates(ListNode *head) {
        for (ListNode *l = head; l;) {
            if ( l->next && l->val == l->next->val ) l->next = l->next->next;
            else l = l->next;
        }
        return head;
    }
};
