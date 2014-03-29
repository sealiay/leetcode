class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        size_t s = 0, n = matrix.size();
        while ( n > 1 ) {
            --n;
            for (size_t i = 0; i < n; ++i) {
                int a = matrix[s][s+i];
                matrix[s][s+i] = matrix[s+n-i][s];
                matrix[s+n-i][s] = matrix[s+n][s+n-i];
                matrix[s+n][s+n-i] = matrix[s+i][s+n];
                matrix[s+i][s+n] = a;
            }
            --n;
            ++s;
        }
    }
};
