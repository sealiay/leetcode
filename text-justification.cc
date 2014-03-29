class Solution {
public:
    typedef vector<string>::iterator I;
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> rt;
        for (I b = words.begin(); b != words.end(); ) {
            rt.emplace_back();
            tie(rt.back(), b) = ln(b, words.end(), L);
        }
        return move(rt);
    }
    
    pair<I, size_t> ct(I b, I e, size_t l) {
        size_t t = b->size(), c = b->size();
        ++b;
        while ( b != e && t + 1 + b->size() <= l ) {
            t += 1 + b->size();
            c += b->size();
            ++b;
        }
        return make_pair(b, c);
    }
    
    pair<string, I> ln(I b, I e, size_t l) {
        I p;
        size_t c;
        tie(p, c) = ct(b, e, l);
        if ( p == e || b+1 == p ) return make_pair(lt(b, p, c, l), p);
        return make_pair(md(b, p, c, l), p);
    }
    
    string lt(I b, I e, size_t, size_t l) {
        string r = *b++;
        while ( b != e ) r.append(1, ' ').append(*b++);
        r.append(l - r.size(), ' ');
        return move(r);
    }
    
    string md(I b, I e, size_t c, size_t l) {
        size_t s = (l-c) / (e-b-1), i = (l-c) % (e-b-1);
        string r = *b++;
        while ( b != e && i-- > 0 ) r.append(s+1, ' ').append(*b++);
        while ( b != e ) r.append(s, ' ').append(*b++);
        return move(r);
    }
};
