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
    bool isValidBST(TreeNode *root) {
        int b, e;
        return v(root, b, e);
    }
    
    bool v(TreeNode *n, int &b, int &s) {
        if ( !n ) {
            b = INT_MIN;
            s = INT_MAX;
            return true;
        }
        int bl, sl, br, sr;
        bool fl = v(n->left, bl, sl);
        bool fr = v(n->right, br, sr);
        if ( !fl || !fr ) return false;
        b = max(n->val, br);
        s = min(n->val, sl);
        return bl < n->val && sr > n->val;
    }
};
