class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int m = num[0] + num[1] + num[2];
        for (int k = 2; k < num.size(); ++k) {
            int i = 0, j = k - 1;
            while ( i < j ) {
                int v = num[i] + num[j] + num[k];
                if ( v == target) return v;
                else if ( v < target ) ++i;
                else if ( v > target ) --j;
                if ( abs(target - m) > abs(target - v) ) m = v;
            }
        }
        return m;
    }
};
