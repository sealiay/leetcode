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
    bool hasPathSum(TreeNode *root, int sum) {
        if ( !root ) return false;
        sum -= root->val;
        if ( !(root->left) && !(root->right) ) {
            return sum == 0;
        }
        bool h = false;
        if ( root->left ) h =  hasPathSum(root->left, sum);
        if ( !h && root->right ) h =  hasPathSum(root->right, sum);
        return h;
    }
};
