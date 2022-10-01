#ifndef __0201_H
#define __0201_H

/*****************************************************
Description:
Given two integers left and right that represent the range [left, right], return the
bitwise AND of all numbers in this range, inclusive.

Example 1:
Input: left = 5, right = 7
Output: 4

Example 2:
Input: left = 0, right = 0
Output: 0

Example 3:
Input: left = 1, right = 2147483647
Output: 0

Constraints:
0 <= left <= right <= 2^31 - 1
*****************************************************/

#include "../includes.hpp"

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        auto bit_cnt = [](int val) -> int {
            int bc = 0;
            while (val > 0) {
                bc += 1;
                val = val >> 1;
            }
            return bc;
        };

        auto remove_high_bit = [&](int val) -> int {
            int bc = bit_cnt(val);
            val &= (~(1 << (bc - 1)));
            return val;
        };

        int left_bit_cnt = bit_cnt(left), right_bit_cnt = bit_cnt(right);
        int rst = 0;

        while (left_bit_cnt == right_bit_cnt && left_bit_cnt != 0) {
            rst += (1 << (left_bit_cnt - 1));
            left = remove_high_bit(left);
            right = remove_high_bit(right);
            left_bit_cnt = bit_cnt(left);
            right_bit_cnt = bit_cnt(right);
        }
        return rst;
    }
};

#endif
