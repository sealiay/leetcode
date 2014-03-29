class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if ( strs.empty() ) return "";
        string a = strs.front();
        for (string &s : strs) {
            size_t i = 0;
            for (i = 0; i < s.size() && i < a.size() && a[i] == s[i]; ++i);
            a.erase(i);
        }
        return move(a);
    }
};
