#ifndef __0056_H
#define __0056_H

/*************************************************
Description:
Given a collection of intervals, merge all overlapping intervals.

Example 1:
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default
code definition to get new method signature.
*************************************************/

#include "../includes.hpp"

class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(),
             [](vector<int> a, vector<int> b) -> bool { return a[0] < b[0]; });

        int totalcnt = intervals.size(); // for speed
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i - 1][1] >= intervals[i][0]) {
                intervals[i][0] = min(intervals[i][0], intervals[i - 1][0]);
                intervals[i][1] = max(intervals[i][1], intervals[i - 1][1]);
                intervals[i - 1][0] = 0;
                intervals[i - 1][1] = -1;
                totalcnt--;
            }
        }
        vector<vector<int>> res(totalcnt);
        int pos = 0;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] <= intervals[i][1]) {
                res[pos++] = intervals[i];
            }
        }
        return res;
    }
};

#endif
