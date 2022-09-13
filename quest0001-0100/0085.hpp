#ifndef __0085_H
#define __0085_H

/**********************************************
Description:
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example:
Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6
**********************************************/

#include "includes.hpp"

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;
        // Convert the `m*n` 2D maximal rectangle problem to `m` 1D maximal rectangle
        for (int i=0; i<matrix.size(); i++) {
            int curRow = i;
            vector<int> heights;
            for (int j=0; j<matrix[i].size(); j++) {
                for (curRow=i; curRow<matrix.size(); curRow++) {
                    if (matrix[curRow][j] == '0')
                        break;
                }
                heights.push_back(curRow-i);
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0, right = 0, left = 0, height = 0;
        stack<int> increHeight;
        heights.push_back(0);
        for (int i=0; i<heights.size(); i++) {
            // if heights[i] < heights[i-1], i can be the right boundary
            if (!increHeight.empty() && heights[increHeight.top()] > heights[i]) {  
                right = i;
                while (!increHeight.empty() && heights[increHeight.top()] > heights[i]) {  // compute area of each idx with left boundary
                    height = heights[increHeight.top()];
                    increHeight.pop();
                    if (!increHeight.empty())
                        left = increHeight.top();
                    else
                        left = -1;
                    maxArea = max(maxArea, (right-left-1) * height);
                }
            }
            increHeight.push(i);
        } 
        return maxArea;
    }
};

#endif