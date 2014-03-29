class Solution {
public:
    typedef string::iterator I;
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        return wb(s.begin(), s.end(), dict);
    }
    
    vector<string> wb(I b, I e, const unordered_set<string> &dt) {
        vector<string> an;
        string c = {b, e};
        if ( dt.count(c) ) an.push_back(c);
        for (I i = b+1; i != e; ++i) {
            string c = {i, e};
            if ( dt.count(c) == 0 ) continue;
            vector<string> nn = wb(b, i, dt);
            for (string &s : nn) an.push_back(move(s) + ' ' + c);
        }
        return move(an);
    }
};
