class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> a;
        a.resize(n);
        for (auto &r : a) r.resize(n);
        size_t s = 0;
        int v = 1;
        while ( n > 1 ) {
            --n;
            for (size_t j = s; j != s + n; ++j) a[s][j] = v++;
            for (size_t i = s; i != s + n; ++i) a[i][s + n] = v++;
            for (size_t j = s + n; j != s; --j) a[s + n][j] = v++;
            for (size_t i = s + n; i != s; --i) a[i][s] = v++;
            ++s;
            --n;
        }
        if ( n == 1 ) {
            a[s][s] = v++;
        }
        return move(a);
    }
};
