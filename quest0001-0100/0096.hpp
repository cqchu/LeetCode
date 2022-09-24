#ifndef __0096_H
#define __0096_H

/****************************************************
Description:
Given n, how many structurally unique BST's (binary search trees) that store
values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

****************************************************/

#include "../includes.hpp"

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                int m = dp[j] == 0 ? 1 : dp[j];
                int n = dp[i - j - 1] == 0 ? 1 : dp[i - j - 1];

                dp[i] += m * n;
            }
        }
        return dp[n];
    }
};
#endif