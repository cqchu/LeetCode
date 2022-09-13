#ifndef __0168_H
#define __0168_H

/*****************************************************
Description:
Given an integer columnNumber, return its corresponding column title as it
appears in an Excel sheet.

For example:
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...

Example 1:
Input: columnNumber = 1
Output: "A"

Example 2:
Input: columnNumber = 28
Output: "AB"

Example 3:
Input: columnNumber = 701
Output: "ZY"

Constraints:
1 <= columnNumber <= 2^31 - 1
*****************************************************/

#include "../includes.hpp"

class Solution {
  public:
    string convertToTitle(int columnNumber) {
        stringstream ss;
        while (columnNumber != 0) {
            ss << static_cast<char>((columnNumber - 1) % 26 + 'A');
            // cout << columnNumber << " " << columnNumber-1 / 26  << " " <<
            // static_cast<char>((columnNumber-1) % 26 + 'A') << endl;
            columnNumber = (columnNumber - 1) / 26;
        }
        string res = ss.str();
        reverse(res.begin(), res.end());
        return res;
    }
};

#endif
