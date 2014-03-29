class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        size_t m = matrix.size();
        if ( m == 0 ) return false;
        size_t n = matrix.front().size();
        size_t i = 0, j = m * n;
        while ( i < j ) {
            size_t k = i + (j - i) / 2;
            int v = matrix[k / n][k % n];
            if ( v == target ) return true;
            else if ( v < target ) i = k + 1;
            else j = k;
        }
        return false;
    }
};
