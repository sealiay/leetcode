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
    bool isBalanced(TreeNode *root) {
        int d;
        return f(root, d);
    }
    
    bool f(TreeNode *t, int &d) {
        if ( !t ) {
            d = 0;
            return true;
        }
        int dl, dr;
        if ( f(t->left, dl) && f(t->right, dr) && abs(dl - dr) < 2 ) {
            d = max(dl, dr) + 1;
            return true;
        }
        return false;
    }
};
