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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> a;
        vector<TreeNode *> s;
        TreeNode *n = root;
        while ( true ) {
            while ( n ) {
                a.push_back(n->val);
                s.push_back(n->right);
                n = n->left;
            }
            if ( s.empty() ) break;
            n = s.back();
            s.pop_back();
        }
        return move(a);
    }
};
