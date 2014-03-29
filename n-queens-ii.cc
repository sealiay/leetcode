class Solution {
public:
    int totalNQueens(int n) {
        bool c[100] = {}, l[100] = {}, r[100] = {};
        int w = 0;
        fill(c, l, r, 0, n, w);
        return w;
    }
    
    void fill(bool c[], bool l[], bool r[], int i, int n, int &w) {
        if ( i == n ) {
            ++w;
            return;
        }
        for (int j = 0; j < n; ++j) {
            if ( c[j] || l[i + j] || r[i - j + 50] ) continue;
            c[j] = l[i + j] = r[i - j + 50] = true;
            fill(c, l, r, i + 1, n, w);
            c[j] = l[i + j] = r[i - j + 50] = false;
        }
    }
};
