#ifndef __0227_H
#define __0227_H

/*****************************************************
Description:
Given a string s which represents an expression, evaluate this expression and return its
value. The integer division should truncate toward zero. You may assume that the given
expression is always valid. All intermediate results will be in the range of [-231, 231
- 1].

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
non-negative integers in the range [0, 231 - 1]. The answer is guaranteed to fit in a
32-bit integer.
*****************************************************/

#include "../includes.hpp"

class Solution {
public:
    long do_eval(long lhs, long rhs, char op) {
        if (op == '+') {
            return lhs + rhs;
        } else if (op == '-') {
            return lhs - rhs;
        } else if (op == '*') {
            return lhs * rhs;
        } else {
            return lhs / rhs;
        }
    }
    int calculate(string str) {
        std::vector<char> expr;
        expr.reserve(str.size() + 1);
        for (auto c : str) {
            if (c != ' ') {
                expr.push_back(c);
            }
        }

        std::stack<char> vals;

        for (size_t i = 0; i < expr.size(); ++i) {
            if (expr[i] == '+' || expr[i] == '-') {
                if (ops.empty() || ops.top() == '(') {
                    push_val();
                } else {
                    // (ops.top() == '+' || ops.top() == '-')
                    push_val();
                    eval();
                }
                ops.push(expr[i]);
            } else if (expr[i] == '(') {
                // push_val();
                ops.push(expr[i]);
            } else if (expr[i] == ')') {
                push_val();
                while (ops.top() != '(') {
                    eval();
                }
                ops.pop();
            } else {
                val = val * 10 + expr[i] - '0';
                has_val = true;
            }
        }
        return vals.top();
    }
};

#endif
