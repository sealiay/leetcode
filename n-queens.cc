class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        bool c[100] = {}, l[100] = {}, r[100] = {};
        int x[100];
        vector<vector<string>> w;
        fill(c, l, r, x, 0, n, w);
        return move(w);
    }
    
    void fill(bool c[], bool l[], bool r[], int x[], int i, int n, vector<vector<string>> &w) {
        if ( i == n ) {
            vector<string> a = {(size_t)n, string((size_t)n, '.')};
            for (i = 0 ; i < n; ++i) {
                a[i][x[i]] = 'Q';
            }
            w.push_back(move(a));
            return;
        }
        for (int j = 0; j < n; ++j) {
            if ( c[j] || l[i + j] || r[i - j + 50] ) continue;
            x[i] = j;
            c[j] = l[i + j] = r[i - j + 50] = true;
            fill(c, l, r, x, i + 1, n, w);
            c[j] = l[i + j] = r[i - j + 50] = false;
        }
    }
};
