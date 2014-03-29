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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> a;
        if ( !root ) return move(a);
        vector<int> c;
        p(root, sum, a, c);
        return move(a);
    }
    
    void p(TreeNode *t, int s, vector<vector<int>> &a, vector<int> &c) {
        s -= t->val;
        c.push_back(t->val);
        if ( s == 0 && !t->left && !t->right ) a.push_back(c);
        if ( t->left ) p(t->left, s, a, c);
        if ( t->right ) p(t->right, s, a, c);
        c.pop_back();
    }
};
