class Solution {
public:
    int minDistance(string word1, string word2) {
        size_t m = word1.size() + 1, n = word2.size() + 1;
        vector<int> a, b;
        a.resize(n, 0);
        b.resize(n, 0);
        iota(a.begin(), a.end(), 0);
        for (size_t i = 1; i < m; ++i) {
            b[0] = (int)i;
            for (size_t j = 1; j < n; ++j) {
                b[j] = min(a[j], b[j-1]) + 1;
                b[j] = min(b[j], a[j-1] + (word1[i-1] != word2[j-1]));
            }
            swap(a, b);
        }
        return a.back();
    }
};
