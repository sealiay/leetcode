class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        vector<vector<int>> &o = obstacleGrid;
        size_t m = o.size();
        if ( m == 0 ) return 1;
        size_t n = o.front().size();
        if ( n == 0 ) return 1;
        
        for (size_t i = m; i-- > 0;) {
            for (size_t j = n; j-- > 0;) {
                if ( o[i][j] == 1 ) {
                    o[i][j] = 0;
                    continue;
                }
                if ( i == m - 1 && j == n - 1 ) o[i][j] = 1;
                if ( i + 1 < m ) o[i][j] += o[i+1][j];
                if ( j + 1 < n ) o[i][j] += o[i][j+1];
            }
        }
        return o[0][0];
    }
};
