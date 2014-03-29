class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> &d = digits;
        for (auto i = d.rbegin(); i != d.rend(); ++i) {
            if ( *i < 9 ) {
                ++(*i);
                return d;
            } else *i = 0;
        }
        d.insert(d.begin(), 1);
        return d;
    }
};
