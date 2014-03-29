class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> &r = ratings;
        if ( r.size() < 2 ) return r.size();
        int s = 0, c = 0;
        while ( true ) {
            int t = tp(r, s, greater_equal<int>());
            int b = tp(r, t, less_equal<int>());
            c += cd(s, t, b, r);
            s = b;
            if ( s == r.size() - 1 ) break; 
            if ( r[s] == r[s+1] ) ++s;
            else --c;
        }
        return c;
    }
    
    int cd(int l, int c, int r, const vector<int> &v) {
        l = c - l;
        r = r - c;
        return (l+1)*l/2 + (r+1)*r/2 + max(l, r)+1;
    }
    
    template <typename F>
    int tp(const vector<int> &r, int s, F f) {
        for (int i = s; i < r.size()-1; ++i) {
            if ( f(r[i], r[i+1]) ) return i;
        }
        return r.size()-1;
    }
};
