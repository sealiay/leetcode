class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> s;
        for (int n : num) {
            s.insert(n);
        }
        int m = 1;
        for (int n : num) {
            int c = 1;
            for (int i = n + 1; s.count(i); ++i) {
                ++c;
                s.erase(i);
            }
            for (int i = n - 1; s.count(i); --i) {
                ++c;
                s.erase(i);
            }
            m = max(m, c);
        }
        return m;
    }
};
