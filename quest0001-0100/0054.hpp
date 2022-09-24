#ifndef __0054_H
#define __0054_H

/*************************************************
Description:
Given a matrix of m x n elements (m rows, n columns), return all elements of
the matrix in spiral order.

Example 1:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*************************************************/

#include "../includes.hpp"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        if (matrix.size() == 0) {
            return vector<int>(0);
        }
        int row = matrix.size(), col = matrix[0].size();
        vector<int> res(row * col);
        int top = 0, down = row, left = 0, right = col;
        int cnt = 0;
        while (cnt < row * col) {
            for (int i = left; i < right; i++) {
                res[cnt++] = matrix[top][i];
            }
            if ((++top) >= down)
                break;
            for (int i = top; i < down; i++) {
                res[cnt++] = matrix[i][right - 1];
            }
            if ((--right) <= left)
                break;
            for (int i = right - 1; i >= left; i--) {
                res[cnt++] = matrix[down - 1][i];
            }
            if ((--down) <= top)
                break;
            for (int i = down - 1; i >= top; i--) {
                res[cnt++] = matrix[i][left];
            }
            if ((++left) >= right)
                break;
        }
        return res;
    }
};

#endif
