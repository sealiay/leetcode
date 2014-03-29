class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        if ( numRows == 0 ) return {};
        vector<vector<int>> a = {{1}};
        for (int r = 2; r <= numRows; ++r) {
            vector<int> c = {1};
            vector<int> &p = a.back();
            for (int j = 1; j < r - 1; ++j) {
                c.push_back(p[j-1] + p[j]);
            }
            c.push_back(1);
            a.push_back(c);
        }
        return move(a);
    }
};
