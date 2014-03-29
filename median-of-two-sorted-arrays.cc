class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        double u = fd(A, A+m, B, B+n, (m+n-0) / 2);
        double b = fd(A, A+m, B, B+n, (m+n-1) / 2);
        return (u + b) /2;
    }
    
    int fd(int *b1, int *e1, int *b2, int *e2, size_t k) {
        while ( b1 != e1 && b2 != e2 ) {
            size_t i = (e1-b1) / 2;
            size_t j = lower_bound(b2, e2, b1[i]) - b2;
            if ( k < i+j ) {
                e1 = b1 + i;
                e2 = b2 + j;
            } else if ( k == i+j ) {
                return b1[i];
            } else {
                b1 += i+1;
                b2 += j;
                k -= i+j+1;
            }
        }
        if ( b1 == e1 ) return b2[k];
        if ( b2 == e2 ) return b1[k];
    }
};
