#ifndef __0073_H
#define __0073_H

/****************************************************
Description:
Given a m x n matrix, if an element is 0, set its entire row and column to 0.
Do it in-place.

Example 1:
Input:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]

Example 2:
Input:
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output:
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

Follow up:
    A straight forward solution using O(mn) space is probably a bad idea.
    A simple improvement uses O(m + n) space, but still not the best solution.
    Could you devise a constant space solution?
****************************************************/

#include "../includes.hpp"

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        vector<int> row, col;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }

        for (auto r : row) {
            for (int i = 0; i < matrix[r].size(); i++) {
                matrix[r][i] = 0;
            }
        }

        for (auto c : col) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][c] = 0;
            }
        }
    }
};

#endif