#ifndef __0028_H
#define __0028_H

/**********************************************************
Description:
Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle
is not part of haystack.

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1
**********************************************************/

#include "../includes.hpp"

class Solution {
  public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0)
            return 0;
        if (needle.length() > haystack.length())
            return -1;

        int idx = -1;

        for (int i = 0; i < haystack.length() - needle.length() + 1; i++) {
            if (haystack.substr(i, needle.length()).compare(needle) == 0) {
                idx = i;
                break;
            }
        }
        return idx;
    }
};

#endif
