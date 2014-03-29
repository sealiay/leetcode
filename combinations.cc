class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> a = {vector<int>(k, 0)};
        iota(a.back().begin(), a.back().end(), 1);
        while ( true ) {
            vector<int> c = a.back();
            auto r = c.rbegin();
            while ( r != c.rend() && *r + (int)(r - c.rbegin()) >= n ) {
                ++r;
            }
            if ( r == c.rend() ) return move(a);
            iota(r.base() - 1, c.end(), *r + 1);
            a.push_back(move(c));
        }
    }
};
