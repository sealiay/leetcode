class Solution {
public:
    typedef string::iterator I;
    string longestPalindrome(string s) {
        pair<I, I> m, c;
        for (I i = s.begin(); i != s.end(); ++i) {
            c = lp1(s.begin(), s.end(), i);
            if ( c.second - c.first > m.second - m.first ) m = c;
            c = lp2(s.begin(), s.end(), i);
            if ( c.second - c.first > m.second - m.first ) m = c;
        }
        return string(m.first, m.second);
    }

    pair<I, I> lp1(I b, I e, I c) {
        size_t i = 0;
        while ( i <= c-b && i < e-c && *(c-i) == *(c+i) ) ++i;
        return make_pair(c-i+1, c+i);
    }

    pair<I, I> lp2(I b, I e, I c) {
        size_t i = 0;
        while ( i <= c-b && i < e-c-1 && *(c-i) == *(c+i+1) ) ++i;
        return make_pair(c-i+1, c+i+1);
    }
};
