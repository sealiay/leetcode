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
    int maxDepth(TreeNode *root) {
        struct E { TreeNode *n; int d; };
        vector<E> s = {E{root, 0}};
        int m = 0;
        while ( !s.empty() ) {
            E e = s.back();
            s.pop_back();
            if ( e.n ) {
                s.push_back(E{e.n->left, e.d + 1});
                s.push_back(E{e.n->right, e.d + 1});
            } else m = max(m, e.d);
        }
        return m;
    }
};
