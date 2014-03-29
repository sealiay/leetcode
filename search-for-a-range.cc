class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        auto p = er(A, A + n, target);
        if ( p.first == p.second ) return {-1, -1};
        return {p.first - A, p.second - A - 1};
    }
    
    pair<int *, int *> er(int *b, int *e, int t) {
        return {l(b, e, t), u(b, e, t)};
    }
    
    int *l(int *b, int *e, int t) {
        while ( b < e ) {
            int *m = b + (e - b) / 2;
            int v = *m;
            if ( v < t ) b = m + 1;
            else e = m;
        }
        return b;
    }
    
    int *u(int *b, int *e, int t) {
        while ( b < e ) {
            int *m = b + (e - b) / 2;
            int v = *m;
            if ( v <= t ) b = m + 1;
            else e = m;
        }
        return b;
    }
};
