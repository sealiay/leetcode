/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        while ( root ) {
            TreeLinkNode *n = root;
            root = first_child(n);
            TreeLinkNode *c = root, *s;
            while ( c ) {
                TreeLinkNode *s = next_child(c, n);
                c->next = s;
                c = s;
            }
        }
    }
    
    TreeLinkNode *first_child(TreeLinkNode *&n) {
        while ( n ) {
            if ( n->left ) return n->left;
            if ( n->right ) return n->right;
            n = n->next;
        }
        return nullptr;
    }
    
    TreeLinkNode *next_child(TreeLinkNode *c, TreeLinkNode *&n) {
        while ( n ) {
            if ( c == n->left ) {
                if ( n->right ) return n->right;
            } else if ( c == n->right );
            else if ( n->left ) return n->left;
            else if ( n->right ) return n->right;
            n = n->next;
        }
        return nullptr;
    }
};
