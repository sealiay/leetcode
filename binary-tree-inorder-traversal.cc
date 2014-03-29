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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> a;
        vector<TreeNode *> s;
        TreeNode *n = root;
        while ( true ) {
            while ( n ) {
                s.push_back(n);
                n = n->left;
            }
            if ( s.empty() ) break;
            n = s.back();
            s.pop_back();
            a.push_back(n->val);
            n = n->right;
        }
        return move(a);
    }
};
