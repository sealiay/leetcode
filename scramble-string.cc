class Solution {
public:
    bool isScramble(string s1, string s2) {
        return s1.size() == s2.size() && is(s1.begin(), s2.begin(), s1.size());
    }
    bool an(string::iterator s1, string::iterator s2, size_t n) {
        int w[256] = {};
        for (size_t i = 0; i < n; ++i) {
            ++w[*(s1 + i)];
            --w[*(s2 + i)];
        }
        for (int v : w) if ( v != 0 ) return false;
        return true;
    }
    bool is(string::iterator s1, string::iterator s2, size_t n) {
        if ( equal(s1, s1 + n, s2) ) return true;
        if ( !an(s1, s2, n) ) return false;
        for (size_t i = 1; i < n; ++i) {
            if ( is(s1, s2, i) && is(s1+i, s2+i, n-i) ) return true;
            if ( is(s1, s2 + n-i, i) && is(s1 + i, s2, n-i) ) return true;
        }
        return false;
    }
};
