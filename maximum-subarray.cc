class Solution {
public:
    int maxSubArray(int A[], int n) {
        int m = -INT_MAX, p = 0;
        for (int i = 0; i < n; ++i) {
            p = max(p, 0) + A[i];
            m = max(m, p);
        }
        return m;
    }
};
