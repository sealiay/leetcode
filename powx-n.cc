class Solution {
public:
    double pow(double x, int n) {
        x = n >= 0 ? x : 1/x;
        n = abs(n);
        double r = 1;
        while  ( n ) {
            if ( n % 2 ) r *= x;
            x *= x;
            n /= 2;
        }
        return r;
    }
};
