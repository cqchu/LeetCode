#ifndef __0074_H
#define __0074_H

/****************************************************
Description:
Write an efficient algorithm that searches for a value in an m x n matrix. This
matrix has the following properties: Integers in each row are sorted from left
to right. The first integer of each row is greater than the last integer of the
previous row.

Example 1:
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true

Example 2:
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
****************************************************/

#include "../includes.hpp"

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.size() == 0 or matrix[0].size() == 0)
            return false;
        int rowStart = 0, rowEnd = matrix.size(), colStart = 0,
            colEnd = matrix[0].size();
        int rowMid = 0, colMid = 0;
        while (rowStart < rowEnd) {
            rowMid = (rowStart + rowEnd) / 2;
            if (matrix[rowMid][colStart] <= target &&
                matrix[rowMid][colEnd - 1] >= target)
                break;
            else if (matrix[rowMid][colStart] > target)
                rowEnd = rowMid;
            else
                rowStart = rowMid + 1;
        }

        while (colStart < colEnd) {
            colMid = (colStart + colEnd) / 2;
            if (matrix[rowMid][colMid] == target)
                return true;
            else if (matrix[rowMid][colMid] > target)
                colEnd = colMid;
            else
                colStart = colMid + 1;
        }

        return false;
    }
};

#endif