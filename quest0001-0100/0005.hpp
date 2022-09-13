#ifndef __0005_H
#define __0005_H

/*************************************************************
Description:
Given a string s, find the longest palindromic substring in s.
You may assume that the maximum length of s is 1000.

Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: "cbbd"
Output: "bb"
**************************************************************/

#include "../includes.hpp"

class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        int maxLen = 0, startIdx = 0;
        for(int i=0; i<s.length(); i++)
        {
            int offset1 = 0;
            while(offset1<=i && s[i-offset1]==s[i+offset1])
                offset1++;

            int offset2 = 0;
            while(offset2<=i && s[i-offset2]==s[i+1+offset2])
                offset2++;

            int tmpStartIdx = 0, tmpLen = 0;
            if(offset2*2 > (offset1-1)*2 + 1)
            {
                tmpLen = offset2*2;
                tmpStartIdx = i+1 - offset2;
            }
            else
            {
                tmpLen = (offset1-1)*2 + 1;
                tmpStartIdx = i+1 - offset1;
            }

            if(tmpLen > maxLen)
            {
                maxLen = tmpLen;
                startIdx = tmpStartIdx;
            }
        }
        return s.substr(startIdx, maxLen);
    }
};

#endif
