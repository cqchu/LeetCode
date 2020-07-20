#ifndef __0006_H
#define __0006_H

/**********************************************************
Description:
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);

Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
**********************************************************/

#include "includes.hpp"

class Solution {
public:
    string convert(string s, int numRows) {
        int patternLen = numRows * 2 - 2;
        if(numRows == 1)
            patternLen = 1;
        string resStr;
        for(int i=0; i<numRows; i++)
        {
            for(int j=0; j<=s.length()/patternLen; j++)
            {
                if(patternLen*j+i < s.length())
                    resStr += s[patternLen*j+i];
                if(i!=0 && i!=numRows-1)
                    if(patternLen*j+patternLen-i < s.length())
                        resStr += s[patternLen*j+patternLen-i];
            }
        }
        return resStr;
    }
};

#endif