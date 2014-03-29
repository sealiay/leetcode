class Solution {
public:
    string multiply(string num1, string num2) {
        if ( num1 == "0" || num2 == "0" ) return "0";
        int c = 0;
        int m = num1.size(), n = num2.size();
        string r;
        r.reserve(m + n);
        for (int k = 0; k < m+n-1; ++k) {
            int s = c;
            for (int i = max(0, k+1-n); i <= k && i < m; ++i) {
                s += (num1.at(m-1-i) - '0') * (num2.at(n-1-(k-i)) - '0');
            }
            r.push_back(s % 10 + '0');
            c = s / 10;
        }
        if (c) r.push_back(c + '0');
        reverse(r.begin(), r.end());
        return move(r);
    }
};
