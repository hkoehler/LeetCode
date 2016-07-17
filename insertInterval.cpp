// https://leetcode.com/problems/insert-interval/

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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        
        if (intervals.empty())
            return {newInterval};

        // insert interval at appropriate position in sorted array
        // due to fact we're dealing with vectore insert will be O(n)
        auto iter = lower_bound(intervals.begin(),
                                intervals.end(),
                                newInterval,
                                [] (const Interval &lhs, const Interval &rhs) {
                                    return lhs.start < rhs.start;
                                });
        intervals.insert(iter, newInterval);
        
        // merge up to 3 intervals in O(n)
        res.push_back(intervals.front());
        for (int i = 1; i < intervals.size(); i++) {
            auto &prev = res.back();
            auto &curr = intervals[i];
            if (prev.end >= curr.start)
                prev.end = max(prev.end, curr.end);
            else
                res.push_back(curr);
        }
        return res;
    }
};
