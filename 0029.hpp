#ifndef __0029_H
#define __0029_H

/**********************************************************
Description:
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
Return the quotient after dividing dividend by divisor.
The integer division should truncate toward zero.

Example 1:
Input: dividend = 10, divisor = 3
Output: 3

Example 2:
Input: dividend = 7, divisor = -3
Output: -2
**********************************************************/

#include <cmath>
#include <iostream>

class Solution {
public:
    int divide(int dividend, int divisor) {
        int op = 1;
        long long dividendl = dividend;
        long long divisorl = divisor;
        if (dividendl == 0 || divisorl == 0)
            return 0;

        if (dividendl > 2147483647 || dividendl < -2147483648)
            return 2147483647;
        if ((dividendl<0 && divisorl>0) || (dividendl>0 && divisorl<0))
            op = -1;

        dividendl = std::abs(dividendl);
        divisorl = std::abs(divisorl);
        long long cnt = 0, tmpDivisor = 0;
        while (dividendl >= divisorl)
        {
            tmpDivisor = divisorl;
            long long tmpCnt = 1;
            while(dividendl >= tmpDivisor)
            {
                tmpDivisor = tmpDivisor << 1;
                if(dividendl >= tmpDivisor)
                    tmpCnt = tmpCnt + tmpCnt;
            }

            cnt = tmpCnt + cnt;
            tmpDivisor = tmpDivisor >> 1;
            dividendl = dividendl - tmpDivisor;
        }

        if(op*cnt != 2147483648)
            return op*cnt;
        else
            return 2147483647;
    }
};

#endif

