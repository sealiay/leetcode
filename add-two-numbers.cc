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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head, **h = &head;
        int c = 0;
        while ( l1 || l2 || c ) {
            int s = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + c;
            *h = new ListNode(s % 10);
            c = s / 10;
            
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
            h = &(*h)->next;
        }
        *h = nullptr;
        return head;
    }
};
