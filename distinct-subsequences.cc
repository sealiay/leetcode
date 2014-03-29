class Solution {
public:
    int numDistinct(string S, string T) {
        size_t m = S.size(), n = T.size();
        vector<int> a(m+1, 1), b(m+1, 0);
        for (size_t j = n; j-- > 0; ) {
            for (size_t i = m; i-- > 0; ) {
                b[i] = b[i+1];
                if ( S[i] == T[j] ) b[i] += a[i+1];
            }
            swap(a, b);
            b.back() = 0;
        }
        return a.front();
    }
};
