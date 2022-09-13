#ifndef __0123_H
#define __0123_H

/****************************************************
Description:
Say you have an array for which the ith element is the price of a given stock on
day i. Design an algorithm to find the maximum profit. You may complete at most
two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you
must sell the stock before you buy again).

Example 1:
Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit =
3-0 = 3. Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit =
4-1 = 3.

Example 2:
Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit =
5-1 = 4. Note that you cannot buy on day 1, buy on day 2 and sell them later, as
you are engaging multiple transactions at the same time. You must sell before
buying again.

Example 3:
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
****************************************************/

#include "../includes.hpp"

class Solution {
  public:
    // state 0 -> can buy
    // state 1 -> can sell
    // count -> how many transactions till now 0/1/2
    vector<int> prices;
    int len;
    int dp[100000][2][3];

    int recurse(int depth, int state, int count) {
        if (depth == len) {
            return 0;
        }
        if (count == 2) {
            return 0;
        }
        int &ans = dp[depth][state][count];
        if (ans != -1) {
            return ans;
        }
        if (state == 0) {
            int op1 = recurse(depth + 1, 0, count);
            int op2 = recurse(depth + 1, 1, count) - prices[depth];
            return ans = max(op1, op2);
        }
        if (state == 1) {
            int op1 = recurse(depth + 1, 1, count);
            int op2 = prices[depth] + recurse(depth + 1, 0, count + 1);
            return ans = max(op1, op2);
        }
        return -1;
    }

    int maxProfit(vector<int> &prices) {
        this->prices = prices;
        len = prices.size();
        memset(dp, -1, sizeof(dp));
        return recurse(0, 0, 0);
    }
};

#endif
