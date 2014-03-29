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
    vector<TreeNode *> generateTrees(int n) {
        return g(1, n + 1);
    }
    
    vector<TreeNode *> g(int b, int e) {
        if ( e - b < 1 ) return {nullptr};
        vector<TreeNode *> a;
        for (int i = b; i < e; ++i) {
            vector<TreeNode *> ls = g(b, i);
            vector<TreeNode *> rs = g(i + 1, e);
            for (TreeNode *l : ls) {
                for (TreeNode *r : rs) {
                    TreeNode *t = new TreeNode(i);
                    t->left = cp(l);
                    t->right = cp(r);
                    a.push_back(t);
                }
            }
            for (TreeNode *l : ls) dl(l);
            for (TreeNode *r : rs) dl(r);
        }
        return a;
    }
    
    void dl(TreeNode *t) {
        if ( t ) {
            dl(t->left);
            dl(t->right);
            delete t;
        }
    }
    
    TreeNode *cp(TreeNode *t) {
        if ( !t ) return t;
        TreeNode *n = new TreeNode(t->val);
        n->left = cp(t->left);
        n->right = cp(t->right);
        return n;
    }
};
