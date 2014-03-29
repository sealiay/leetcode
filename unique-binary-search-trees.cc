class Solution {
public:
    int numTrees(int n) {
        vector<int> a = {1};
        for (int m = 0; m < n; ++m) {
            a.push_back(0);
            for (int i = 0; i <= m; ++i)
                a.back() += a[i] * a[m - i];
        }
        return a.back();
    }
};
