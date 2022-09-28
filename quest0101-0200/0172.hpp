#ifndef __0172_H
#define __0172_H

/*****************************************************
Description:
Given an integer n, return the number of trailing zeroes in n!.
Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

Example 1:
Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.

Example 2:
Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.

Example 3:
Input: n = 0
Output: 0

Constraints:
0 <= n <= 10^4
*****************************************************/

#include "../includes.hpp"

class Solution {
public:
    //     int trailingZeroes(int n) {
    //         if (n == 0)
    //             return 0;
    //         long tailZeroNum, tailVal;
    //         helper(1, n+1, tailZeroNum, tailVal);
    //         return tailZeroNum;
    //     }

    //     void helper(int startPos, int endPos, long &tailZeroNum, long
    //     &tailVal) {
    //         if (startPos + 1 == endPos) {
    //             tailZeroNum = 0;
    //             tailVal = startPos;
    //         }
    //         else {
    //             long tailZeroNumLeft, tailValLeft, tailZeroNumRight,
    //             tailValRight; long midPos = startPos + (endPos - startPos) /
    //             2; helper(startPos, midPos, tailZeroNumLeft, tailValLeft);
    //             helper(midPos, endPos, tailZeroNumRight, tailValRight);
    //             tailZeroNum = tailZeroNumLeft + tailZeroNumRight;
    //             tailVal = tailValLeft * tailValRight;
    //         }
    //         while (tailVal % 10 == 0) {
    //             tailZeroNum ++;
    //             tailVal /= 10;
    //         }
    //         tailVal = tailVal % 100000;
    //     }
    int trailingZeroes(int n) { return n / 5 + n / 25 + n / 125 + n / 625 + n / 3125; }
};

#endif
