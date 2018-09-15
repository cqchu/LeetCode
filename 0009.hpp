#ifndef __0009_H
#define __0009_H

/**********************************************************
Description:
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:
Input: 121
Output: true

Example 2:
Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Follow up:
Coud you solve it without converting the integer to a string?
**********************************************************/

#include <cmath>

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        if(x < 10)
            return true;

        int xLeft, xRight, xLen = 0;
        for(int xtmp=x; xtmp!=0; xtmp/=10)
            xLen ++;
        
        xRight = x % ((int)pow(10, xLen/2));
        xLeft = x / ((int)pow(10, (xLen+1)/2));

        for(int i=xLen/2; i>0; i--)
        {
            if(xLeft/((int)pow(10, i-1)) != xRight % 10)
                return false;
            xLeft = xLeft % ((int)pow(10, i-1));
            xRight = xRight / 10;
        }
        return true;
    }
};

#endif
