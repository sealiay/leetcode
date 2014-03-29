/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        if ( !root ) return 0;
        struct E { int d; TreeNode *n; };
        deque<E> q;
        q.push_back(E{0, root});
        while ( !q.empty() ) {
            E e = q.front();
            q.pop_front();
            if ( !e.n->left && !e.n->right ) return e.d + 1;
            if ( e.n->left ) q.push_back(E{e.d + 1, e.n->left});
            if ( e.n->right ) q.push_back(E{e.d + 1, e.n->right});
        }
    }
};
