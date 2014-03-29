class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int r[9] = {}, c[9] = {}, s[9] = {};
        for (size_t i = 0; i < 9; ++i) {
            for (size_t j = 0; j < 9; ++j) {
                char w = board[i][j];
                if ( w == '.' ) continue;
                int v = 1 << (w - '0');
                if ( (r[i] & v) || (c[j] & v) || (s[i / 3 * 3 + j / 3] & v) ) return false;
                r[i] |= v;
                c[j] |= v;
                s[i / 3 * 3 + j / 3] |= v;
            }
        }
        return true;
    }
};
