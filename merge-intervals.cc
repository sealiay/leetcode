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
    vector<Interval> merge(vector<Interval> &intervals) {
        if ( intervals.empty() ) return vector<Interval>();
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval & b) {
            return tie(a.start, a.end) < tie(b.start, b.end);
        });
        vector<Interval> r = {intervals.front()};
        for (auto &i : intervals) {
            if ( i.start <= r.back().end ) r.back().end = max(r.back().end, i.end);
            else r.push_back(i);
        }
        return move(r);
    }
};
