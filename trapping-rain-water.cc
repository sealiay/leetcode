class Solution {
public:
    int trap(int A[], int n) {
        if ( n < 3 ) return 0;
        int m = 0;
        int i = 0, j = n - 1;
        int l = A[i], r = A[j];
        while ( i < j - 1 ) {
            if ( l < r ) {
                ++i;
                l = max(A[i], l);
                m += l - A[i];
            } else {
                --j;
                r = max(A[j], r);
                m += r - A[j];
            }
        }
        return m;
    }
};
