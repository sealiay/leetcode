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
    int sumNumbers(TreeNode *root) {
        if ( !root ) return 0;
        struct E { TreeNode *n; int v; };
        vector<E> s = {E{root, root->val}};
        int m = 0;
        while ( !s.empty() ) {
            E e = s.back();
            s.pop_back();
            if ( !e.n->left && !e.n->right ) m += e.v;
            if ( e.n->right ) s.push_back(E{e.n->right, e.v * 10 + e.n->right->val});
            if ( e.n->left ) s.push_back(E{e.n->left, e.v * 10 + e.n->left->val});
        }
        return m;
    }
};
