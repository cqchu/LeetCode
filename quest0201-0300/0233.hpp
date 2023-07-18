#ifndef __0233_H
#define __0233_H

/*****************************************************
Description:
Given an integer n, count the total number of digit 1 appearing in all non-negative
integers less than or equal to n.

Example 1:
Input: n = 13
Output: 6

Example 2:
Input: n = 0
Output: 0

Constraints:
0 <= n <= 10^9
*****************************************************/

#include "../includes.hpp"

class Solution {
public:
    int helper(int n) {
        if (n <= 0) {
            return 0;
        }
        int ret = 0;
        while (n > 0) {
            if (n % 10 == 1) {
                ret += 1;
            }
            n = n / 10;
        }
        return ret;
    }

    int helper(int start, int end) {
        int ret = 0;
        for (int i = start; i <= end; ++i) {
            ret += helper(i);
        }
        return ret;
    }

    int get_max_count_of_order(int order) {
        // order = 1, {0~9}, have 1 `1`
        // order = 2, {0~99}, have 20 `1`
        // order = 3, {0~999}, have 300 `1`
        if (order == 0) {
            return 0;
        }
        return static_cast<int>(std::pow(10, order - 1) * order);
    }

    int get_num_order(int val) {
        if (val == 0) {
            return 0;
        }

        for (int order = 0; order < 20; ++order) {
            if (static_cast<long>(std::pow(10, order)) > val) {
                return order;
            }
        }

        return -1;
    }

    int countDigitOne(int n) {
        if (n <= 0) {
            return 0;
        }

        int ret = 0;

        int order = get_num_order(n);
        while (order > 0) {
            int unit = std::pow(10, order - 1);
            int val = n / unit;

            ret += val * get_max_count_of_order(order - 1);
            if (val > 1) {
                ret += unit;
            } else if (val == 1) {
                ret += (n - unit + 1);
            }

            n = n % unit;
            order = order - 1;
        }
        return ret;
    }
};

#endif
