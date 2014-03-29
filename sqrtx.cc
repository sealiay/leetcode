class Solution {
public:
    int sqrt(int x) {
        long long i = (long long)x, j = -1;
        while ( i - j > 0 ) {
            long long m = i - (i - j) / 2;
            if ( m * m > (long long)x ) i = m - 1;
            else j = m;
        }
        return (int)i;
    }
};
