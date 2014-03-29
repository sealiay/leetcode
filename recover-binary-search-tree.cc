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
    TreeNode *er[2];
    bool g = false;
    void recoverTree(TreeNode *root) {
        TreeNode *c = root;
        TreeNode *p = nullptr;
        while ( c ) {
            if ( !c->left ) {
                test(p, c);
                p = c;
                c = c->right;
            } else {
                TreeNode *q = c->left;
                while ( q->right && q->right != c ) q = q->right;
                if ( q->right == c ) {
                    test(q, c);
                    q->right = nullptr;
                    p = c;
                    c = c->right;
                } else {
                    q->right = c;
                    c = c->left;
                }
            }
        }
        swap(er[0]->val, er[1]->val);
        return;
    }
    
    void test(TreeNode *l, TreeNode *n) {
        if ( l && l->val > n->val ) {
            if ( !g ) {
                er[0] = l;
                er[1] = n;
                g = true;
            } else {
                er[1] = n;
            }
        }
    }
};
