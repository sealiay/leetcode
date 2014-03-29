class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        struct E { string s; int p; };
        deque<E> qq;
        qq.push_back(E{start, 2});
        while ( !qq.empty() ) {
            E e = qq.front();
            qq.pop_front();
            if ( hm(e.s, end) == 1 ) return e.p;
            for (auto i = dict.begin(); i != dict.end(); ) {
                if ( hm(e.s, *i) == 1 ) {
                    qq.push_back(E{move(*i), e.p+1});
                    i = dict.erase(i);
                } else ++i;
            }
        }
        return 0;
    }
    
    int hm(const string &a, const string &b) {
        int h = 0;
        for (size_t i = 0; i < a.size() && h < 2; ++i) if ( a[i] != b[i] ) ++h;
        return h;
    }
};
