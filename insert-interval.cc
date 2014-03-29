/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> r;
        Interval &n = newInterval;
        vector<Interval>::iterator a;
        vector<Interval>::reverse_iterator b;
        for (a = intervals.begin(); a != intervals.end() && a->end < n.start; ++a);
        for (b = intervals.rbegin(); b != intervals.rend() && b->start > n.end; ++b);
        if ( a != intervals.end() ) n.start = min(n.start, a->start);
        if ( b != intervals.rend() ) n.end = max(n.end, b->end);
        for (auto i = intervals.begin(); i != a; ++i) r.push_back(*i);
        r.push_back(n);
        for (auto i = b.base(); i != intervals.end(); ++i) r.push_back(*i);
        return move(r);
    }
};
