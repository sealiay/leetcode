class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        size_t m = s1.size(), n = s2.size();
        if ( m + n != s3.size() ) return false;
        
        vector<bool> a, b;
        a.assign(n+1, false);
        b.assign(n+1, false);
        
        a[n] = true;
        for (size_t j = n; j-- > 0; ) {
            a[j] = s2[j] == s3[m+j] && a[j+1];
        }
        for (size_t i = m; i-- > 0; ) {
            b[n] = s1[i] == s3[i+n] && a[n];
            for (size_t j = n; j-- > 0; ) {
                b[j] = (s1[i] == s3[i+j] && a[j]) || (s2[j] == s3[i+j] && b[j+1]);
            }
            swap(a, b);
        }
        return a.front();
    }
};
