class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        size_t m = matrix.size();
        if ( m == 0 ) return {};
        size_t n = matrix.front().size();
        if ( n == 0 ) return {};
        size_t s = 0;
        vector<int> r;
        r.reserve(m * n);
        while ( s < (m+1)/2 && s < (n+1)/2 ) {
            size_t p = m-s-s-1, q = n-s-s-1;
            if ( p == 0 || q == 0 ) 
                for (size_t i = 0; i < p+1; ++i) 
                    for (size_t j = 0; j < q+1; ++j)
                        r.push_back(matrix[s+i][s+j]);
            else {
                for (size_t j = 0; j < q; ++j) r.push_back(matrix[s+0][s+j]);
                for (size_t i = 0; i < p; ++i) r.push_back(matrix[s+i][s+q]);
                for (size_t j = q; j > 0; --j) r.push_back(matrix[s+p][s+j]);
                for (size_t i = p; i > 0; --i) r.push_back(matrix[s+i][s+0]);
            }
            ++s;
        }
        return move(r);
    }
};
