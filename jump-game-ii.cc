class Solution {
public:
    int jump(int A[], int n) {
        int r = 0, l = 0, c = 0;
        for (int i = 0; i < n; ++i) {
            if ( i > l ) {
                l = c;
                ++r;
            }
            c = max(c, i+A[i]);
        }
        return r;
    }
};
