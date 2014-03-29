class Solution {
public:
    vector<int> grayCode(int n) {
        n = 1 << n;
        vector<int> a = {0};
        for (int i = 1; i < n; ++i) {
            a.push_back(a.back() ^ (i & -i));
        }
        return move(a);
    }
};
