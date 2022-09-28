#ifndef __0188_H
#define __0188_H

/*****************************************************
Description:
You are given an integer array prices where prices[i] is the price of a given
stock on the ith day, and an integer k. Find the maximum profit you can achieve.
You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must
sell the stock before you buy again).

Example 1:
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit =
4-2 = 2.

Example 2:
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit =
6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit =
3-0 = 3.

Constraints:

1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000
*****************************************************/

#include "../includes.hpp"

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        LOG_ARRAY(prices);
        vector<int> cost(k + 1, INT_MAX), profit(k + 1, 0);
        for (int i = 0; i < prices.size(); i++) {
            for (int j = 1; j <= k; j++) {
                cost[j] = min(cost[j], prices[i] - profit[j - 1]);
                profit[j] = max(profit[j], prices[i] - cost[j]);
                LOG_ARRAY(cost);
                LOG_ARRAY(profit);
            }
        }
        return profit[k];
    }
};

#endif
