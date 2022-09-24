#ifndef __0050_H
#define __0050_H

/*************************************************
Description:
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:
Input: 2.00000, 10
Output: 1024.00000

Example 2:
Input: 2.10000, 3
Output: 9.26100

Example 3:
Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

Note:
    -100.0 < x < 100.0
    n is a 32-bit signed integer, within the range [?231, 231 ? 1]
*************************************************/

#include "../includes.hpp"

// �ݹ���ֵ���
// �������ʱ�仹����, Ȼ����Ϊ�ұߵ�����ߣ�����ֱ�Ӹ��ý��
// ��ʱʱ�临�Ӷ�ΪO(logn)
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0 && n < 0)
            return numeric_limits<double>::infinity();
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        if (n == -1)
            return 1 / x;

        // int nLeft = n/2;
        // int nRight = n - nLeft;
        // double lres = myPow(x, nLeft);
        // double rres = myPow(x, nRight);
        int halfN = n / 2;
        double tres = myPow(x, halfN);
        double t = n > 0 ? x : 1 / x;
        if (n % 2 == 0)
            return tres * tres;
        else
            return tres * tres * t;
    }
};

#endif
