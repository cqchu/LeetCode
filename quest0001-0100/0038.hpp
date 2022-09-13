#ifndef __0038_H
#define __0038_H

/************************************************
Description:
The count-and-say sequence is the sequence of integers with the first five terms as following:
1.     1
2.     11
3.     21
4.     1211
5.     111221

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 �� n �� 30, generate the nth term of the count-and-say sequence.
Note: Each term of the sequence of integers will be represented as a string.

Example 1:
Input: 1
Output: "1"

Example 2:
Input: 4
Output: "1211"
************************************************/

#include "../includes.hpp"

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return string("1");
        }
        string sN_1 = countAndSay(n-1);
        string sN;
        char tc = sN_1[0];
        int cnt = 1;
        for(int i=1; i<sN_1.size(); i++) {
            if (sN_1[i] != tc) {
                sN = sN + to_string(cnt) + tc;
                cnt = 1;
                tc = sN_1[i];
            }
            else {
                cnt = cnt + 1;
            }
        }
        sN = sN + to_string(cnt) + tc;
        return sN;
    }
};

#endif

