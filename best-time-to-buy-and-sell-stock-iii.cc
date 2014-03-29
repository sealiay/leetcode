class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if ( prices.size() < 2 ) return 0;
        int a = 0, b = 0, m = 0, p = 0;
        for (size_t i = 0; i < prices.size() - 1; ++i) {
            int n = prices[i+1] - prices[i];
            a = max(a + n, n);
            b = max(max(b, p) + n, a);
            p = max(a, p);
            m = max(b, m);
        }
        return m;
    }
};
