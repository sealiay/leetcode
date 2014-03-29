class Solution {
public:
    typedef vector<int>::iterator It;
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> a = {vector<int>()};
        sort(S.begin(), S.end());
        for (It i = S.begin(); i != S.end(); i = e(a, i, S.end()));
        return move(a);
    }
    
    It e(vector<vector<int>> &a, It b, It e) {
        vector<vector<int>> o = a;
        It i = b;
        while ( i != e && *b == *i ) {
            ++i;
            for (auto &c : o) {
                auto d = c;
                d.insert(d.end(), b, i);
                a.push_back(move(d));
            }
        }
        return i;
    }
};
