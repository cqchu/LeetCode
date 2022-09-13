#ifndef __0119_H
#define __0119_H

/****************************************************
Description:
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
Note that the row index starts from 0.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:
Input: 3
Output: [1,3,3,1]

Follow up:
Could you optimize your algorithm to use only O(k) extra space?
****************************************************/

#include "../includes.hpp"

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
    
    vector<int> getRow(int rowIndex) {
        return generate(rowIndex+1)[rowIndex];
    }
};

#endif
