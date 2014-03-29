class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        struct s { int v, i; };
        vector<s> a;
        int n = 0;
        for (int v : numbers) {
            a.push_back(s{v, ++n});
        }
        sort(a.begin(), a.end(), [](const s &a, const s &b) { return a.v < b.v; });
        auto i = a.begin();
        auto j = a.rbegin();
        while ( true ) {
            if ( i->v + j->v < target ) ++i;
            if ( i->v + j->v > target ) ++j;
            if ( i->v + j->v == target ) return {min(i->i, j->i), max(i->i, j->i)};
        }
    }
};
