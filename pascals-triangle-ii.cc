class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> a, b;
        a.resize(rowIndex + 1);
        b.resize(rowIndex + 1);
        a[0] = 1;
        for (int r = 1; r <= rowIndex; ++r) {
            b[0] = 1;
            for (int i = 1; i < r; ++i) {
                b[i] = a[i - 1] + a[i];
            }
            b[r] = 1;
            swap(a, b);
        }
        return move(a);
    }
};
