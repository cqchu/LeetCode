#ifndef __0056_H
#define __0056_H

/*************************************************
Description:
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times.

Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*************************************************/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        if (intervals.size() == 0)
            res.push_back(newInterval);
        
        bool insertComplete = false;
        for (int i=0; i<intervals.size(); i++) {
            if (intervals[i][1] < newInterval[0]) {
                res.push_back(intervals[i]);
                if (i+1 >= intervals.size()) {
                    res.push_back(newInterval);
                }
            }
            
            else if (intervals[i][0] > newInterval[1]) {
                if (!insertComplete) {
                    res.push_back(newInterval);
                    insertComplete = true;
                }
                res.push_back(intervals[i]);
            }
            
            else if (intervals[i][1] >= newInterval[0] && intervals[i][0] <= newInterval[1]) { // merge
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                if (i+1 >= intervals.size()) {
                    res.push_back(newInterval);
                }
            }
            
            
            
        }
        return res;
    }
};


#endif
