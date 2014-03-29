class Solution {
public:
    vector<string> letterCombinations(string digits) {
        char m[10][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> w;
        string a = digits;
        f(m, 0, digits, a, w);
        return move(w);
    }
    
    void f(const char m[10][5], size_t i, const string &d, string &a, vector<string> &w) {
        if ( i == d.size() ) {
            w.push_back(a);
            return;
        }
        const char *l = m[d[i] - '0'];
        while ( *l ) {
            a[i] = *l++;
            f(m, i + 1, d, a, w);
        }
    }
};
