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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return c(num.data(), num.size());
    }
    
    TreeNode *c(const int *a, size_t n) {
        if ( n == 0 ) return nullptr;
        size_t l = n / 2;
        TreeNode *t = new TreeNode(a[l]);
        t->left = c(a, l);
        t->right = c(a + l + 1, n - l - 1);
        return t;
    }
};
