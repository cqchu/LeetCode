#ifndef __0224_H
#define __0224_H

/*****************************************************
Description:
Given a string s representing a valid expression, implement a basic calculator to
evaluate it, and return the result of the evaluation. Note: You are not allowed to use
any built-in function which evaluates strings as mathematical expressions, such as
eval().

Example 1:
Input: s = "1 + 1"
Output: 2

Example 2:
Input: s = " 2-1 + 2 "
Output: 3

Example 3:
Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23

Constraints:
1 <= s.length <= 3 * 10^5
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer.
*****************************************************/

#include "../includes.hpp"

class Solution {
public:
    long do_eval(long lhs, long rhs, char op) {
        if (op == '+') {
            return lhs + rhs;
        } else {
            return lhs - rhs;
        }
    }
    int calculate(string str) {
        std::vector<char> expr;
        expr.reserve(str.size() + 1);
        expr.push_back('(');
        for (auto c : str) {
            if (c != ' ') {
                expr.push_back(c);
            }
        }
        expr.push_back(')');

        std::stack<long> vals;
        std::stack<char> ops;
        long val = 0;
        bool has_val = false;

        auto eval = [&]() -> void {
            char op = ops.top();
            ops.pop();
            if (op == 'n') {
                long tmp = vals.top();
                vals.pop();
                vals.push(-tmp);
            } else {
                long rhs = vals.top();
                vals.pop();
                long lhs = vals.top();
                vals.pop();
                vals.push(do_eval(lhs, rhs, op));
            }
        };

        auto push_val = [&]() -> void {
            if (has_val) {
                vals.push(val);
                val = 0;
                has_val = false;
            }
        };

        for (size_t i = 0; i < expr.size(); ++i) {
            if (expr[i] == '-') {
                if (expr[i - 1] == '(') {
                    ops.push('n');
                    continue;
                }
            }
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
