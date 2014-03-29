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
    int mmm = INT_MIN;
    int maxPathSum(TreeNode *root) {
        if ( !root ) return 0;
        ps(root);
        return mmm;
    }
    int ps(TreeNode *n) {
        if ( !n ) return 0;
        int t = n->val;
        int l = 0, r = 0;
        if ( n->left ) l = ps(n->left);
        if ( n->right ) r = ps(n->right);
        t = max(max(l, r), 0) + t;
        mmm = max(mmm, max(l + r + n->val, t));
        return t;
    }
};
