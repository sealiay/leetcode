class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int m = 0, p = 0;
        for (size_t i = 1; i < prices.size(); ++i) {
            p = max(p, 0) + prices[i] - prices[i - 1];
            m = max(p, m);
        }
        return m;
    }
};