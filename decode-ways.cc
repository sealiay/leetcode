class Solution {
public:
    int numDecodings(string s) {
        if ( s.empty() || s.front() == '0' ) return 0;
        int a = 1, b = 1;
        for (size_t i = 1; i < s.size(); ++i) {
            int c = 0;
            if ( 0 < g1(s, i) && g1(s, i) < 10 ) c += b;
            if ( 9 < g2(s, i) && g2(s, i) < 27 ) c += a;
            a = b;
            b = c;
        }
        return b;
    }
    int g1(const string &s, size_t i) {
        return s[i] - '0';
    }
    int g2(const string &s, size_t i) {
        return g1(s, i-1) * 10 + g1(s, i);
    }
};
