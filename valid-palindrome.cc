class Solution {
public:
    bool isPalindrome(string s) {
        auto b = s.begin(), e = s.end();
        auto r = s.rbegin(), d = s.rend();
        while ( true ) {
            b = nt(b, e);
            r = nt(r, d);
            if ( b == e ) return true;
            if ( tolower(*b++) != tolower(*r++) ) return false;
        }
    }
    template <typename I> I nt(I i, I e) {
        while ( i != e && !isalnum(*i) ) ++i;
        return i;
    }
};
