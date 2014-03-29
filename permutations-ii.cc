class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int>> a;
        vector<int> c = num;
        sort(c.begin(), c.end());
        a.push_back(c);
        while ( true ) {
            int i = c.size() - 2, j = c.size() - 1;
            while ( i >= 0 && c[i] >= c[i + 1] ) --i;
            if ( i < 0 ) return move(a);
            while ( c[j] <= c[i] ) --j;
            swap(c[i], c[j]);
            reverse(c.begin() + i + 1, c.end());
            a.push_back(c);
        }
    }
};
