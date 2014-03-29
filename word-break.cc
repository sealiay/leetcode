class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> v;
        v.assign(s.size(), false);
        for (size_t i = s.size(); i-- > 0; ) {
            if ( dict.count(string(s, i)) > 0 ) v[i] = true;
            else for (size_t j = i+1; j < s.size(); ++j) {
                if ( v[j] && dict.count(string(s, i, j-i)) > 0 ) {
                    v[i] = true;
                    break;
                }
            }
        }
        return v.front();
    }
};
