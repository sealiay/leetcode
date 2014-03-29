class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int i = num.size() - 2, j = num.size() - 1;
        while ( i >= 0 && num[i] >= num[i + 1] ) --i;
        if ( i >= 0 ) {
            while ( num[j] <= num[i] ) --j;
            swap(num[i], num[j]);
        }
        reverse(num.begin() + i + 1, num.end());
    }
};
