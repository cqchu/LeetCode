#ifndef __0223_H
#define __0223_H

/*****************************************************
Description:
Given the coordinates of two rectilinear rectangles in a 2D plane, return the total area
covered by the two rectangles. The first rectangle is defined by its bottom-left corner
(ax1, ay1) and its top-right corner (ax2, ay2). The second rectangle is defined by its
bottom-left corner (bx1, by1) and its top-right corner (bx2, by2).

Example 1:
Rectangle Area
Input: ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
Output: 45

Example 2:
Input: ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2
Output: 16

Constraints:
-10^4 <= ax1 <= ax2 <= 10^4
-10^4 <= ay1 <= ay2 <= 10^4
-10^4 <= bx1 <= bx2 <= 10^4
-10^4 <= by1 <= by2 <= 10^4
*****************************************************/

#include "../includes.hpp"

class Solution {
public:
    int overlapArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2,
                    int by2) {
        auto overlapLen = [](int a1, int a2, int b1, int b2) -> int {
            int a = std::max(a1, b1);
            int b = std::min(a2, b2);
            return std::max(0, b - a);
        };
        return overlapLen(ax1, ax2, bx1, bx2) * overlapLen(ay1, ay2, by1, by2);
    }

    int rectangleArea(int x1, int y1, int x2, int y2) { return (x2 - x1) * (y2 - y1); }

    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2,
                    int by2) {
        return rectangleArea(ax1, ay1, ax2, ay2) + rectangleArea(bx1, by1, bx2, by2) -
               overlapArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
    }
};

#endif
