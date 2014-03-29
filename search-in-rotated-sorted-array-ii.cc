class Solution {
public:
    bool search(int A[], int n, int target) {
        int i = 1, j = n, s = n;
		while ( j - i > 5 ) {
				int k = i + (j - i) / 2;
				if ( A[k] <= A[n - 1] ) j = k + 1;
				else if ( A[k] >= A[0] ) i = k + 1;
		}
		for (s = i; s < j && A[s] >= A[s - 1]; ++s);
		s = s == j ? 0 : s;
        i = 0;
        j = n;
        while ( i < j ) {
            int k = i + (j - i) / 2;
            int v = A[(k + s) % n];
            if ( v == target ) return true;
            else if ( v < target ) i = k + 1;
            else j = k;
        }
        return false;
    }
};
