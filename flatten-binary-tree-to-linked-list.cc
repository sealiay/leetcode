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
    void flatten(TreeNode *root) {
        if ( !root ) return;
        vector<TreeNode *> s = {root};
        while ( !s.empty() ) {
            TreeNode *n = s.back();
            s.pop_back();
            if ( n->right ) s.push_back(n->right);
            if ( n->left ) s.push_back(n->left);
            n->right = s.empty() ? nullptr : s.back();
            n->left = nullptr;
        }
    }
};
