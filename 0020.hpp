#ifndef __0020_H
#define __0020_H

/**********************************************************
Description:
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:
Input: "()"
Output: true

Example 2:
Input: "()[]{}"
Output: true

Example 3:
Input: "(]"
Output: false

Example 4:
Input: "([)]"
Output: false

Example 5:
Input: "{[]}"
Output: true
**********************************************************/

#include "includes.hpp"

class Solution {
public:
    bool isValid(string s) {
        vector<char> charStack;
        int idx = 0;
        for(idx=0; idx<s.length(); idx++)
        {
            if(s[idx] == '[' || s[idx] == '{' || s[idx] == '(')
                charStack.push_back(s[idx]);
            else
            {
                if(charStack.size() == 0)
                    return false;
                char tmp = charStack[charStack.size() - 1];
                charStack.pop_back();
                if((tmp=='[' && s[idx]!=']') || (tmp=='(' && s[idx]!=')') || (tmp=='{' && s[idx]!='}'))
                    return false;
            }
        }

        if(charStack.size() == 0)
            return true;
        else
            return false;
    }
};

#endif
