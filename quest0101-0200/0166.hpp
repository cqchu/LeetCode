#ifndef __0166_H
#define __0166_H

/*****************************************************
Description:
Given two integers representing the numerator and denominator of a fraction,
return the fraction in string format. If the fractional part is repeating,
enclose the repeating part in parentheses. If multiple answers are possible,
return any of them. It is guaranteed that the length of the answer string is
less than 104 for all the given inputs.

Example 1:
Input: numerator = 1, denominator = 2
Output: "0.5"

Example 2:
Input: numerator = 2, denominator = 1
Output: "2"

Example 3:
Input: numerator = 4, denominator = 333
Output: "0.(012)"

Constraints:
-2^31 <= numerator, denominator <= 2^31 - 1
denominator != 0
*****************************************************/

#include "../includes.hpp"

class Solution {
  public:
    string fractionToDecimal(int numerator, int denominator) {
        unordered_map<long, int> history;
        stringstream ss;
        long cur_num = static_cast<long>(numerator);

        if (cur_num < 0 && denominator > 0) {
            ss << "-";
            cur_num = -cur_num;
        } else if (cur_num > 0 && denominator < 0) {
            ss << "-";
            denominator = -denominator;
        }

        ss << cur_num / denominator;
        cur_num = (cur_num % denominator) * 10;
        if (cur_num == 0)
            return ss.str();

        ss << ".";
        int pos = ss.str().size();
        while (cur_num != 0) {
            if (history.find(cur_num) != history.end()) {
                ss << ")";
                string res = ss.str();
                res.insert(history[cur_num], "(");
                return res;
            }
            history.insert(pair<long, int>(cur_num, pos));
            ss << cur_num / denominator;
            cur_num = (cur_num % denominator) * 10;
            pos++;
        }
        return ss.str();
    }
};

#endif
