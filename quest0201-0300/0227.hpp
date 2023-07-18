#ifndef __0227_H
#define __0227_H

/*****************************************************
Description:
Given a string s which represents an expression, evaluate this expression and return its
value. The integer division should truncate toward zero. You may assume that the given
expression is always valid. All intermediate results will be in the range of [-2^31,
2^31 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as
mathematical expressions, such as eval().

Example 1:
Input: s = "3+2*2"
Output: 7

Example 2:
Input: s = " 3/2 "
Output: 1

Example 3:
Input: s = " 3+5 / 2 "
Output: 5

Constraints:
1 <= s.length <= 3 * 10^5
s consists of integers and operators ('+', '-', '*', '/') separated by some number of
spaces. s represents a valid expression. All the integers in the expression are
non-negative integers in the range [0, 2^31 - 1]. The answer is guaranteed to fit in a
32-bit integer.
*****************************************************/

#include "../includes.hpp"

class Solution {
public:
    int do_eval(int lhs, int rhs, char op) {
        if (op == '+') {
            return lhs + rhs;
        } else if (op == '-') {
            return lhs - rhs;
        } else if (op == '*') {
            return lhs * rhs;
        } else {
            assert(op == '/');
            return lhs / rhs;
        }
    }

    int calculate(string s) {
        s.push_back('$');

        std::stack<char> operators;
        std::stack<int> operands;

        std::unordered_map<char, int> op_priority = {
            {'$', 0}, {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

        long operand = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                operand = operand * 10 + s[i] - '0';
            } else if (op_priority.find(s[i]) != op_priority.end()) {
                operands.emplace(operand);
                operand = 0;

                if (!operators.empty()) {
                    while (!operators.empty() &&
                           op_priority[s[i]] <= op_priority[operators.top()]) {
                        int rhs = operands.top();
                        operands.pop();
                        int lhs = operands.top();
                        operands.pop();
                        char pre_op = operators.top();
                        operators.pop();

                        int res = do_eval(lhs, rhs, pre_op);
                        operands.emplace(res);
                    }
                }

                operators.emplace(s[i]);
            } else {
                continue;
            }
        }
        return operands.top();
    }
};

#endif
