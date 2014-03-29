class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> a;
        a.push_back({""});
        for (int i = 1; i <= n; ++i) {
            g(i, a);
        }
        return a.back();
    }
    
    void g(int n, vector<vector<string>> &a) {
        a.emplace_back();
        vector<string> &c = a.back();
        for (int i = 0; i < n; ++i) {
            vector<string> &p = a[i], &q = a[n - 1 - i];
            for (string &x : p)
                for (string &y : q)
                    c.push_back("(" + x + ")" + y);
        }
    }
};
