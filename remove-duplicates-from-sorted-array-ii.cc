class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if ( n < 2 ) return n;
        int j = 0;
        for (int i = 0; i < n - 2; ++i) {
            if ( A[i] == A[i + 1] && A[i] == A[i + 2] ) continue;
            A[j++] = A[i];
        }
        A[j++] = A[n - 2];
        A[j++] = A[n - 1];
        return j;
    }
};
