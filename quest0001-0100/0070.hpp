#ifndef __0070_H
#define __0070_H

/********************************************
Description:
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you
climb to the top?

Note: Given n will be a positive integer.

Example 1:
Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
********************************************/

#include "../includes.hpp"

class Solution {
public:
    int climbStairs(int n) {
        // vector<int> dp(n);
        // if (n == 0)
        //     return 0;
        // else if (n == 1)
        //     return 1;
        // else if (n == 2)
        //     return 2;
        // dp[0] = 1;
        // dp[1] = 2;

        // for (int i=2; i<n; i++) {
        //     dp[i] = dp[i-1] + dp[i-2];
        // }
        // return dp[n-1];

        // use less space
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        else if (n == 2)
            return 2;

        vector<int> dp(3);
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i < n; i++) {
            dp[i % 3] = dp[(i - 1) % 3] + dp[(i - 2) % 3];
            // cout << dp[i%3] << " = " << dp[(i-1)%3] << " + " <<
            // dp[(i-2)%3] << endl;
        }
        return dp[(n - 1) % 3];
    }
};

#endif
