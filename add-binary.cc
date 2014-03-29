class Solution {
public:
    string addBinary(string a, string b) {
        if ( a.size() < b.size() ) swap(a, b);
        int c = 0;
        for (size_t i = 0; i < a.size(); ++i) {
            int s = g(a, i) + g(b, i) + c;
            a[a.size() - 1 - i] = (char)(s % 2 + '0');
            c = s / 2;
        }
        if ( c ) a.insert(a.begin(), '1');
        return move(a);
    }
    
    int g(const string &s, size_t i) {
        return i >= s.size() ? 0 : (int)(s[s.size() - 1 - i] - '0');
    }
};
