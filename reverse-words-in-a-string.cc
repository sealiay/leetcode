class Solution {
public:
    typedef string::iterator I;
    void reverseWords(string &s) {
        char l = ' ';
        I e = s.begin();
        for (auto c : s) if ( c != ' ' || l != ' ' ) *e++ = l = c;
        s.erase(e, s.end());
        if ( !s.empty() && s.back() == ' ' ) s.pop_back();
        for (I i = s.begin(); i != s.end(); ) {
            i = find_if(i, s.end(), [] (char c) { return c != ' '; });
            e = find(i, s.end(), ' ');
            reverse(i, e);
            i = e;
        }
        reverse(s.begin(), s.end());
    }
    
    
};
