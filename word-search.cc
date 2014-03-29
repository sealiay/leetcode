class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if ( word.empty() ) return true;
        size_t m = board.size();
        if ( m == 0 ) return false;
        size_t n = board.front().size();
        if ( n == 0 ) return false;
        
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if ( ee(board, i, j, word.begin(), word.end()) )
                    return true;
            }
        }
        return false;
    }
    
    bool ee(vector<vector<char>> &bd, size_t i, size_t j, string::iterator b, string::iterator e) {
        if ( b == e ) return true;
        if ( i >= bd.size() || j >= bd.front().size() ) return false;
        if ( bd[i][j] != *b ) return false;
        bd[i][j] = '\0';
        bool f = false;
        f = f || ee(bd, i+1, j, b+1, e);
        f = f || ee(bd, i-1, j, b+1, e);
        f = f || ee(bd, i, j+1, b+1, e);
        f = f || ee(bd, i, j-1, b+1, e);
        bd[i][j] = *b;
        return f;
    }
};
