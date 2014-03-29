class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        size_t m = grid.size();
        size_t n = grid.front().size();
        for (size_t i = 1; i < m; ++i) grid[i][0] += grid[i-1][0];
        for (size_t j = 1; j < n; ++j) grid[0][j] += grid[0][j-1];
        for (size_t i = 1; i < m; ++i) {
            for (size_t j = 1; j < n; ++j) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
};
