#ifndef __0151_H
#define __0151_H

/****************************************************
Description:
Given an input string, reverse the string word by word.

Example 1:
Input: "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing
spaces.

Example 3:
Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single
space in the reversed string.

Note:
A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed
string should not contain leading or trailing spaces. You need to reduce
multiple spaces between two words to a single space in the reversed string.

Follow up:
For C programmers, try to solve it in-place in O(1) extra space.
****************************************************/

#include "../includes.hpp"

class Solution {
public:
    int updataStartPos(int startPos, string &s) {
        while (startPos < s.size() && s[startPos] == ' ')
            startPos++;
        return startPos;
    }
    int findEndPos(int endPos, string &s) {
        while (endPos < s.size() && s[endPos] != ' ')
            endPos++;
        return endPos;
    }
    string reverseWords(string s) {
        vector<string> stk;
        int startPos = 0, endPos = 0;
        while (startPos < s.size()) {
            startPos = updataStartPos(startPos, s);
            if (startPos >= s.size())
                break;
            endPos = findEndPos(startPos, s);
            stk.push_back(s.substr(startPos, endPos - startPos));
            startPos = endPos;
        }

        string res;
        if (stk.size() == 0)
            return res;
        while (stk.size() > 1) {
            res.append(stk[stk.size() - 1]);
            res.append(" ");
            stk.pop_back();
        }
        res.append(stk[0]);

        return res;
    }
};

#endif