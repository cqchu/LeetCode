#ifndef __0150_H
#define __0150_H

/****************************************************
Description:
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:
Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.

Example 1:
Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:
Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Example 3:
Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
****************************************************/

#include "includes.hpp"

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> si;
        for (string token: tokens) {
            if (token.size() > 1 || (token[0] >= '0' && token[0] <= '9')) { // number
                si.push(stoi(token));
            }
            else {
                int rhs = si.top();
                si.pop();
                int lhs = si.top();
                si.pop();
                int res = 0;
                if (token[0] == '+') 
                    res = lhs + rhs;
                else if (token[0] == '-') 
                    res = lhs - rhs;
                else if (token[0] == '*') 
                    res = lhs * rhs;
                else if (token[0] == '/') 
                    res = lhs / rhs;
                si.push(res);
            }
        }
        return si.top();
    }
};

#endif