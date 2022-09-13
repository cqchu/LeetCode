#ifndef __0067_H
#define __0067_H

/********************************************
Description:
Given two binary strings, return their sum (also a binary string).
The input strings are both non-empty and contains only characters 1 or 0.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
********************************************/

#include "../includes.hpp"

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0, bitRes = 0, iA = 0, iB = 0;
        string res(max(a.size(), b.size()), '0');
        for (int i=1; i<=max(a.size(), b.size()); i++) {
            iA = iB = 0;
            if (a.size() >= i) {
                iA = a[a.size()-i] - '0';
            }
            if (b.size() >= i) {
                iB = b[b.size()-i] - '0';
            }
            bitRes = (iA + iB + carry) % 2;
            carry = (iA + iB + carry) / 2;
            res[res.size()-i] = bitRes + '0';
        }
        
        if (carry == 1) {
            char chCarry = carry + '0';
            res = chCarry + res;
        }
        return res;
    }
};

#endif
