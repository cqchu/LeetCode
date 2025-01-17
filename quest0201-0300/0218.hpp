#ifndef __0218_H
#define __0218_H

/*****************************************************
Description:
A city's skyline is the outer contour of the silhouette formed by all the buildings in
that city when viewed from a distance. Given the locations and heights of all the
buildings, return the skyline formed by these buildings collectively. The geometric
information of each building is given in the array buildings where buildings[i] =
[left_i, right_i, height_i]:

left_i is the x coordinate of the left edge of the ith building.
right_i is the x coordinate of the right edge of the ith building.
height_i is the height of the ith building.
You may assume all buildings are perfect rectangles grounded on an absolutely flat
surface at height 0.

The skyline should be represented as a list of "key points" sorted by their x-coordinate
in the form [[x1,y1],[x2,y2],...]. Each key point is the left endpoint of some
horizontal segment in the skyline except the last point in the list, which always has a
y-coordinate 0 and is used to mark the skyline's termination where the rightmost
building ends. Any ground between the leftmost and rightmost buildings should be part of
the skyline's contour.

Note: There must be no consecutive horizontal lines of equal height in the output
skyline. For instance, [...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is not acceptable; the
three lines of height 5 should be merged into one in the final output as such: [...,[2
3],[4 5],[12 7],...]

Example 1:
Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
Explanation:
Figure A shows the buildings of the input.
Figure B shows the skyline formed by those buildings. The red points in figure B
represent the key points in the output list.

Example 2:
Input: buildings = [[0,2,3],[2,5,3]]
Output: [[0,3],[5,0]]

Constraints:
1 <= buildings.length <= 10^4
0 <= left_i < right_i <= 2^31 - 1
1 <= height_i <= 2^31 - 1
buildings is sorted by lefti in non-decreasing order.
*****************************************************/

#include "../includes.hpp"
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        vector<vector<int>> ans;
        multiset<int> pq{0};

        vector<pair<int, int>> points;

        for (auto b : buildings) {
            points.push_back({b[0], -b[2]});
            points.push_back({b[1], b[2]});
        }

        sort(points.begin(), points.end());

        int ongoingHeight = 0;

        // points.first = x coordinate, points.second = height
        for (int i = 0; i < points.size(); i++) {
            int currentPoint = points[i].first;
            int heightAtCurrentPoint = points[i].second;

            if (heightAtCurrentPoint < 0) {
                pq.insert(-heightAtCurrentPoint);
            } else {
                pq.erase(pq.find(heightAtCurrentPoint));
            }

            // after inserting/removing heightAtI, if there's a change
            auto pqTop = *pq.rbegin();
            if (ongoingHeight != pqTop) {
                ongoingHeight = pqTop;
                ans.push_back({currentPoint, ongoingHeight});
            }
        }

        return ans;
    }
};

#endif
