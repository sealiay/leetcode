class Solution {
public:
    typedef string::iterator I;
    typedef reverse_iterator<I> R;
    typedef pair<I, I> P;
    string simplifyPath(string path) {
        I b = path.begin(), w = path.begin();
        while ( b != path.end() ) {
            P p = nt(b, path.end());
            b = p.second;
            if ( p.second - p.first == 0 );
            else if ( p.second - p.first == 1 && *p.first == '.' );
            else if ( p.second - p.first == 2 && *p.first == '.' && *(p.first+1) == '.' ) {
                R r = find(R(w), path.rend(), '/');
                w = r.base();
                if ( r != path.rend() ) --w;
            } else {
                *w++ = '/';
                w = copy(p.first, p.second, w);
            }
        }
        path.erase(w, path.end());
        if ( path.empty() ) path.push_back('/');
        return move(path);
    }
    
    P nt(I b, I e) {
        I i = find(++b, e, '/');
        return P(b, i);
    }
};
