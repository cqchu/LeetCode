#ifndef __0084_H
#define __0084_H

/***************************************************
Description:
Given n non-negative integers representing the histogram's bar height where the
width of each bar is 1, find the area of largest rectangle in the histogram.
Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

Example:

Input: [2,1,5,6,2,3]
Output: 10
***************************************************/

#include "../includes.hpp"

class Solution {
  public:
    /**
     * Naive solution(Expansion):
     * iterate through each height to find the left and right boundary.
     * The maxArea can be calculated for the rectangle with current height.
     * But the time complexity is O(n^2), which will caused TLE.
     */
    // int largestRectangleArea(vector<int>& heights) {
    //     int maxArea = 0, left, right;
    //     for (int i=0; i<heights.size(); i++) {
    //         for (left=i; left>=0 && heights[left]>=heights[i]; left--) ;
    //         for (right=i; right<heights.size() &&
    //         heights[right]>=heights[i]; right++); maxArea = max(maxArea,
    //         (right-left-1) * heights[i]);
    //     }
    //     return maxArea;
    // }

    /**
     * Using stack to find the left and right boundary efficiently:
     * All weight
     */
    int largestRectangleArea(vector<int> &heights) {
        int maxArea = 0, right = 0, left = 0, height = 0;
        stack<int> increHeight;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++) {
            // if heights[i] < heights[i-1], i can be the right
            // boundary
            if (!increHeight.empty() &&
                heights[increHeight.top()] > heights[i]) {
                right = i;
                while (!increHeight.empty() &&
                       heights[increHeight.top()] >
                           heights[i]) { // compute area of each
                                         // idx with left boundary
                    height = heights[increHeight.top()];
                    increHeight.pop();
                    if (!increHeight.empty())
                        left = increHeight.top();
                    else
                        left = -1;
                    maxArea = max(maxArea, (right - left - 1) * height);
                }
            }
            increHeight.push(i);
        }
        return maxArea;
    }
};

#endif
