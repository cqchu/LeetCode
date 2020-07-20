#ifndef __0052_H
#define __0052_H

/*************************************************
Description:
The n-queens puzzle is the problem of placing n queens on an n��n chessboard such that no two queens attack each other.
Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example:
Input: 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
*************************************************/

#include "includes.hpp"

class Solution {
public:
    // level: cur row, 
    void recurse(int level, vector<int>& pos, int n, int& sol) {
        if (level == n) {
            sol = sol + 1;
        }
        for (int i=0; i<n; i++) {
            // judge whether can be placed
            bool placeFlag = true;
            for (int j=0; j<level; j++) {
                if (pos[j] == i || pos[j] == i+(level-j) || pos[j] == i-(level-j)) {
                    placeFlag = false;
                    break;
                }
            }
            if (placeFlag == true) {
                pos[level] = i;
                recurse(level+1, pos, n, sol);
                pos[level] = -1;
            }
        }
    }
    int totalNQueens(int n) {
        int res=0;
        vector<int> pos(n, -1);
        recurse(0, pos, n, res);
        return res;
    }
};


#endif
