class Solution {
public:
    bool canJump(int A[], int n) {
        int t = n - 1;
        for (int i = n - 2; i >= 0; --i) if ( i + A[i] >= t ) t = i;
        return t == 0;
    }
};
