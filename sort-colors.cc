class Solution {
public:
    void sortColors(int A[], int n) {
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < n; ++i) {
            switch (A[i]) {
                case 0: A[c++] = A[b]; A[b++] = A[a]; A[a++] = 0; break;
                case 1: A[c++] = A[b]; A[b++] = 1; break;
                case 2: A[c++] = 2; break;
            }
        }
    }
};
