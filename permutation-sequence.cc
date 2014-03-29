class Solution {
public:
    string getPermutation(int n, int k) {
        --k;
        int ff = 1;
        for (int i = 2; i < n; ++i) ff *= i;
        char mm[9];
        iota(mm, mm + n, '1');
        string r;
        for (int i = 0; i < n-1; ++i) {
            int j = k / ff;
            k %= ff;
            ff /= n-1-i;
            r.push_back(mm[j]);
            for (; j < n-1-i; ++j) mm[j] = mm[j+1];
        }
        r.push_back(mm[0]);
        return r;
    }
};
