class Solution {
public:
    int maxArea(vector<int> &height) {
        if ( height.empty() ) return 0;
        size_t i = 0, j = height.size() - 1;
        int w = 0;
        while ( i < j ) {
            int v = (int)(j - i);
            if ( height[i] < height[j] ) {
                v *= height[i++];
            } else {
                v *= height[j--];
            }
            w = max(w, v);
        }
        return w;
    }
};
