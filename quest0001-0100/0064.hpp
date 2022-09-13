#ifndef __0064_H
#define __0064_H

/********************************************
Description:
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.

Example:
Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
********************************************/

#include "../includes.hpp"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // 1D DP
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        vector<int> dp(grid[0].size());
        dp[0] = grid[0][0];
        for (int i=1; i<grid[0].size(); i++) {
            dp[i] = dp[i-1] + grid[0][i];
        }
        for (int i=1; i<grid.size(); i++) {
            for (int j=0; j<grid[i].size(); j++) {
                if (j == 0) {
                    dp[j] = dp[j] + grid[i][j];
                }
                else {
                    dp[j] = min(dp[j-1], dp[j]) + grid[i][j];   
                }
            }
        }
        return dp[grid[0].size()-1];
    }
};

#endif
