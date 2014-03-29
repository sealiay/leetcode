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
    bool isSymmetric(TreeNode *root) {
        if ( !root ) return true;
        return s(root->left, root->right);
    }
    
    bool s(TreeNode *l, TreeNode *r) {
        if ( l && r ) {
            return l->val == r->val && s(l->left, r->right) && s(l->right, r->left);
        }
        return l == r;
    }
};
