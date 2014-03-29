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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return b(preorder.data(), inorder.data(), inorder.size());
    }
    
    TreeNode *b(const int pr[], const int in[], size_t n) {
        if ( n == 0 ) return nullptr;
        int v = pr[0];
        size_t l = find(in, in + n, v) - in;
        TreeNode *t = new TreeNode(v);
        t->left = b(pr + 1, in, l);
        t->right = b(pr + 1 + l, in + l + 1, n - l - 1);
        return t;
    }
};
