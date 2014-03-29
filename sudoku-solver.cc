class Solution {
public:
    bool rr[9][9] = {}, cc[9][9] = {}, oo[9][9] = {};
    void solveSudoku(vector<vector<char> > &board) {
        for (size_t i = 0; i < 81; ++i) {
            char c = board[gr(i)][gc(i)];
            if ( c == '.' ) continue;
            rr[gr(i)][c - '1'] = cc[gc(i)][c - '1'] = oo[go(i)][c - '1'] = true;
        }
        assert(sv(board, 0));
    }
    bool sv(vector<vector<char> > &bd, size_t i) {
        if ( i == 81 ) return true;
        if ( bd[gr(i)][gc(i)] != '.' ) return sv(bd, i + 1);
        for (size_t j = 0; j < 9; ++j) {
            if ( rr[gr(i)][j] || cc[gc(i)][j] || oo[go(i)][j] ) continue;
            rr[gr(i)][j] = cc[gc(i)][j] = oo[go(i)][j] = true;
            bd[gr(i)][gc(i)] = (char)(j + '1');
            if ( sv(bd, i + 1) ) return true;
            bd[gr(i)][gc(i)] = '.';
            rr[gr(i)][j] = cc[gc(i)][j] = oo[go(i)][j] = false;
        }
        return false;
    }
    size_t gr(size_t i) { return i / 9; }
    size_t gc(size_t i) { return i % 9; }
    size_t go(size_t i) { return i / 27 * 3 + i % 9 / 3; }
};
