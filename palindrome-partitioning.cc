class Solution {
public:
    bool is(string::iterator b, string::iterator e) {
        if ( b == e ) return false;
        auto r = string::reverse_iterator(e);
        return equal(b, b + (e - b) / 2, r);
    }
    vector<vector<string>> p(string::iterator b, string::iterator e) {
        vector<vector<string>> a;
        for (auto i = b + 1; i != e; ++i) {
            if ( is(i, e) ) {
                for (vector<string> &n : p(b, i)) {
                    n.emplace_back(i,  e);
                    a.push_back(move(n));
                }
            }
        }
        if ( is(b, e) ) a.push_back(vector<string>{string(b, e)});
        return move(a);
    }
    vector<vector<string>> partition(string s) {
        return p(s.begin(), s.end());
    }
};
