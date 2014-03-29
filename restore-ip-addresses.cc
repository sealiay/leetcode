class Solution {
public:
    typedef string::iterator I;
    vector<string> restoreIpAddresses(string s) {
        if ( s.size() < 4 || s.size() > 12 ) return {};
        I p[5];
        size_t t = 0;
        vector<string> a;
        ip(s.begin(), s.end(), p, t, a);
        return a;
    }
    void ip(I b, I e, I p[], size_t t, vector<string> &a) {
        if ( t == 4 && b == e ) {
            a.emplace_back();
            string &r = a.back();
            r.reserve(16);
            p[t] = e;
            for (size_t j = 0; j < 4; ++j) {
                for (I i = p[j]; i != p[j+1]; ++i) r.push_back(*i);
                r.push_back('.');
            }
            r.pop_back();
            return;
        } else if ( b == e || t == 4 ) return;
        p[t++] = b;
        for (I i = b; i <= e; ++i) {
            if ( vl(b, i) ) ip(i, e, p, t, a);
        }
    }
    bool vl(I b, I e) {
        size_t n = e - b;
        switch (n) {
            case 1: return true;
            case 2: return *b != '0';
            case 3: return *b == '1' || (*b == '2' && (*(b+1) < '5' || (*(b+1) == '5' && *(b+2) <= '5')));
            default: return false;
        }
    }
};
