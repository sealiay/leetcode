class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<int> t = triangle.back();
        for (int i = triangle.size() - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j)
                t[j] = min(t[j], t[j + 1]) + triangle[i][j];
        }
        return t[0];
    }
};
