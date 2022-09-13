#ifndef __0118_H
#define __0118_H

/****************************************************
Description:
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it.
Example:
Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
****************************************************/

#include "includes.hpp"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i=0; i<numRows; i++) {
            vector<int> curRow;
            for (int j=0; j<=i; j++) {
                if (j==0 || j==i)
                    curRow.push_back(1);
                else 
                    curRow.push_back(res[i-1][j-1] + res[i-1][j]);
            }
            res.push_back(curRow);
        }
        return res;
    }
};

#endif
