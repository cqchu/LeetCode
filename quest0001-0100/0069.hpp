#ifndef __0069_H
#define __0069_H

/********************************************
Description:
Implement int sqrt(int x).
Compute and return the square root of x, where x is guaranteed to be a
non-negative integer. Since the return type is an integer, the decimal digits
are truncated and only the integer part of the result is returned.

Example 1:
Input: 4
Output: 2

Example 2:
Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since
             the decimal part is truncated, 2 is returned.
********************************************/

#include "../includes.hpp"

class Solution {
  public:
    int mySqrt(int x) {
        // for (long i=0; i <= x; i++) {
        //     if (i*i == x) {
        //         return i;
        //     }
        //     else if (i*i > x) {
        //         return i-1;
        //     }
        // }
        // return 0;

        long startPos = 0, endPos = x;
        if (x == 1)
            return 1;
        while (startPos < endPos - 1) {
            long midPos = (endPos + startPos) / 2;
            // cout << startPos << midPos << endPos << endl;
            if (midPos * midPos > x) {
                endPos = midPos;
            } else if (midPos * midPos == x) {
                return midPos;
            } else {
                startPos = midPos;
            }
        }
        // cout << startPos << endl;
        return startPos;
    }
};

#endif
