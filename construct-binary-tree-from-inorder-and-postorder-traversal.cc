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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return b(inorder.data(), postorder.data(), inorder.size());
    }
    
    TreeNode *b(const int in[], const int po[], size_t n) {
        if ( n == 0 ) return nullptr;
        int v = po[n - 1];
        size_t l = find(in, in + n, v) - in;
        TreeNode *t = new TreeNode(v);
        t->left = b(in, po, l);
        t->right = b(in + l + 1, po + l, n - l - 1);
        return t;
    }
};
