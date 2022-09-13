#ifndef __0062_H
#define __0062_H

/***************************************************
Description:
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?
Above is a 7 x 3 grid. How many possible unique paths are there?
Note: m and n will be at most 100.

Example 1:
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right

Example 2:
Input: m = 7, n = 3
Output: 28
***************************************************/

#include "includes.hpp"

class Solution {
public:
    int uniquePaths(int m, int n) {
        // if (m == 1 or n == 1) {      // 递归的方法竟然TLE了, 因为很多递归子集重复计算了
        //     return 1;                // 所以回到了50题Pow(x)的那种降低复杂度的方法
        // }                            // 所以这一题使用DP的方式来记载过往计算结果
        // else {                       // 感觉所有的递归都可以转为DP啊
        //     return uniquePaths(m-1, n) + uniquePaths(m, n-1);
        // }
        
        // DP的方法，但空间没有优化，2D DP
        // vector<vector<int>> dp(m, vector<int>(n));
        // for (int i=0; i<m; i++)
        //     dp[i][0] = 1;
        // for (int i=0; i<n; i++)
        //     dp[0][i] = 1;
        // for (int i=1; i<m; i++) {
        //     for (int j=1; j<n; j++) {
        //         dp[i][j] = dp[i-1][j] + dp[i][j-1];
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // return dp[m-1][n-1];
        
        // DP的空间优化版本， 1D DP
        // vector<int> dp(n, 1);
        // for (int i=1; i<m; i++) {
        //     for (int j=1; j<n; j++) {
        //         dp[j] = dp[j] + dp[j-1];
        //     }
        // }
        // return dp[n-1];
        
        //DP的空间再优化版本
        if (m > n) {
            vector<int> dp(n, 1);
            for (int i=1; i<m; i++) {
                for (int j=1; j<n; j++) {
                    dp[j] = dp[j] + dp[j-1];
                }
            }
            return dp[n-1];
        }
        else {
            vector<int> dp(m, 1);
            for (int i=1; i<n; i++) {
                for (int j=1; j<m; j++) {
                    dp[j] = dp[j] + dp[j-1];
                }
            }
            return dp[m-1];
        }
    }
};

#endif