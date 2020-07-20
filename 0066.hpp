#ifndef __0066_H
#define __0066_H

/********************************************
Description:
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:
Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Example 2:
Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
********************************************/

#include "includes.hpp"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        digits[digits.size()-1] = digits[digits.size()-1] + 1;
        for (int i=digits.size()-1; i>=0; i--) {
            int t = digits[i] + carry;
            if (t == 10) {
                carry = 1;
                digits[i] = 0;
            }
            else {
                digits[i] = t;
                carry = 0;
                break;
            }
        }
        
        if (carry == 1) {
            digits.insert(digits.begin(), carry);
        }
        
        return digits;
    }
};

#endif
