#ifndef __0032_H
#define __0032_H

/**********************************************************
Description:
Given a string containing just the characters '(' and ')', find the length of
the longest valid (well-formed) parentheses substring. Example 1: Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:
Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
**********************************************************/

#include "../includes.hpp"

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.length(), 0);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                dp[i] = 0;
            else {
                if (i > 0 && s[i - 1] == '(') {
                    if (i == 1)
                        dp[i] = 2;
                    else
                        dp[i] = dp[i - 2] + 2;
                } else if (i > 0 && i > dp[i - 1] && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + 2;
                    if (i - dp[i - 1] - 2 >= 0)
                        dp[i] = dp[i] + dp[i - dp[i - 1] - 2];
                }
            }
        }
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++)
            if (dp[i] > maxLen)
                maxLen = dp[i];
        return maxLen;
    }
};

#endif
