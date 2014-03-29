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
    bool operator()(ListNode *a, ListNode *b) const {
        if ( a && b ) return a->val > b->val;
        if ( b ) return true;
        return false;
    }
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        lists.push_back(nullptr);
        make_heap(lists.begin(), lists.end(), *this);
        
        ListNode *head, **h = &head, *n;
        while ( (n = min(lists)) ) {
            *h = n;
            h = &n->next;
        }
        *h = n;
        return head;
    }
    
    ListNode *min(vector<ListNode *> &ls) {
        ListNode *r = ls.front();
        if ( !r ) return r;
        ls.front() = nullptr;
        ls.back() = r->next;
        pop_heap(ls.begin(), ls.end(), *this);
        return r;
    }
};
