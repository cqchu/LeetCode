#ifndef __0171_H
#define __0171_H

/*****************************************************
Description:
Given a string columnTitle that represents the column title as appears in an
Excel sheet, return its corresponding column number.

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
Input: columnTitle = "A"
Output: 1

Example 2:
Input: columnTitle = "AB"
Output: 28

Example 3:
Input: columnTitle = "ZY"
Output: 701
*****************************************************/

#include "../includes.hpp"

class Solution {
  public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        for (auto c : columnTitle) {
            res = res * 26;
            res += (c - 'A' + 1);
        }
        return res;
    }
};

#endif
