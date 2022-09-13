#ifndef __0058_H
#define __0058_H

/*************************************************
Description:
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:
Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*************************************************/

#include "../includes.hpp"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int top=0, down=n, left=0, right=n;
        int cnt = 1;
        while(cnt <= n*n) {
            for(int i=left; i<right; i++) {
                res[top][i] = cnt++;
            }
            if ((++top) >= down)
                break;
            for (int i=top; i<down; i++) {
                res[i][right-1] = cnt++;
            }
            if ((--right) <= left)
                break;
            for (int i=right-1; i>=left; i--) {
                res[down-1][i] = cnt++;
            }
            if ((--down) <= top)
                break;
            for (int i=down-1; i>=top; i--) {
                res[i][left] = cnt++;
            }
            if ((++left) >= right)
                break;
        }
        return res;
    }
};


#endif
