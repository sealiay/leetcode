class Solution {
public:
    bool isValid(string s) {
        vector<char> t;
        for (char c : s) {
            if ( c == '(' || c == '[' || c == '{' ) t.push_back(c);
            else if ( t.empty() ) return false;
            else if ( !m(t.back(), c) ) return false;
            else t.pop_back();
        }
        return t.empty();
    }
    
    bool m(char a, char b) {
        return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}');
    }
};
