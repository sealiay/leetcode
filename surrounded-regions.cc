class Solution {
public:
    void solve(vector<vector<char>> &board) {
        size_t m = board.size();
        if ( m < 3 ) return;
        size_t n = board.front().size();
        if ( n < 3 ) return;
        for (size_t i = 0; i < m; ++i) {
            fp(board, i*n +  0 );
            fp(board, i*n + n-1);
        }
        for (size_t j = 0; j < n; ++j) {
            fp(board, ( 0 )*n + j);
            fp(board, (m-1)*n + j);
        }
        for (auto &v : board) for (char &c : v) if ( c == 'O' ) c = 'X';
        for (auto &v : board) for (char &c : v) if ( c == 'A' ) c = 'O';
    }
    void fp(vector<vector<char>> &bd, size_t k) {
        size_t m = bd.size(), n = bd.front().size();
        size_t i = k/n, j = k%n;
        if ( bd[i][j] != 'O' ) return;
        deque<size_t> qq;
        auto pt = [&bd, &qq, m, n] (size_t k) {
            size_t i = k/n, j = k%n;
            if ( i >= m || j >= n || bd[i][j] != 'O' ) return;
            bd[i][j] = 'A';
            qq.push_back(k);
        };
        pt(k);
        while ( !qq.empty() ) {
            k = qq.front();
            qq.pop_front();
            pt(k-1);
            pt(k+1);
            pt(k-n);
            pt(k+n);
        }
    }
    
};
