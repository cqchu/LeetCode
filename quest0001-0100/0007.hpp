#ifndef __0007_H
#define __0007_H

/**********************************************************
Description:
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:
Input: 123
Output: 321

Example 2:
Input: -123
Output: -321

Example 3:
Input: 120
Output: 21

Note:
Assume we are dealing with an environment which could only store integers
within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
of this problem, assume that your function returns 0 when the reversed integer
overflows.
**********************************************************/

#include "../includes.hpp"

class Solution {
  public:
    int reverse(int x) {
        if (fabs(x) > pow(2, 31))
            return 0;

        int num[100];
        for (int i = 0; i < 100; i++)
            num[i] = -1;
        long xtmp = fabs(x);

        for (int i = 0; xtmp != 0; xtmp /= 10, i++)
            num[i] = xtmp % 10;

        long sum = 0;
        for (int i = 0; num[i] != -1; i++) {
            sum = sum * 10 + num[i];
            if (sum > pow(2, 31))
                return 0;
        }

        if (x < 0)
            sum = -sum;
        return sum;
    }
};

#endif
