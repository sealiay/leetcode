class Solution {
public:
    int uniquePaths(int m, int n) {
        int k = min(m, n) - 1;
        n += m - 2;
        long long r = 1;
        for (int i = 0; i < k; ++i) {
            r *= n - i;
            r /= i + 1;
        }
        return r;
    }
};
