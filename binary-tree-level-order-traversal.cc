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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<TreeNode *> v = {root}, h;
        vector<vector<int>> a;
        while ( !v.empty() ) {
            a.emplace_back();
            vector<int> &c = a.back();
            for (TreeNode *n : v) {
                if ( !n ) continue;
                c.push_back(n->val);
                h.push_back(n->left);
                h.push_back(n->right);
            }
            v.clear();
            swap(v, h);
        }
        a.pop_back();
        return move(a);
    }
};
