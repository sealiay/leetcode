class Solution {
public:
    string convert(string S, int nRows) {
        if ( nRows < 2 ) return S;
        string w;
        size_t s = 2 * nRows - 2;
        for (int r = 0; r < nRows; ++r) {
            size_t t = s - 2 * r;
            for (size_t i = r; i < S.size(); i += s) {
                w.push_back(S[i]);
                if ( t != 0 && t != s && i+t < S.size() ) w.push_back(S[i+t]);
            }
        }
        return move(w);
    }
};
