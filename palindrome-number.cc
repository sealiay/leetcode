class Solution {
public:
    bool isPalindrome(int x) {
        if ( x == 0 ) return true;
        if ( x < 0 ) return false;
        int n = 1, y = x;
        while ( (y /= 10) ) n *= 10;
        while ( n > 1 ) {
            if ( x / n != x % 10 ) return false;
            x = x % n / 10;
            n /= 100;
        }
        return true;
    }
};
