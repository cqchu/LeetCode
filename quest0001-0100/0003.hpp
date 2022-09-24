#ifndef __0003_H
#define __0003_H

/*************************************************************************
Description:
Given a string, find the length of the longest substring without repeating
characters.

Example 1:
Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", which the length is 3.

Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence
and not a substring.
**************************************************************************/

#include "../includes.hpp"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0, startIdx = 0, curIdx = 0;
        vector<int> existFlag(128, -1);
        while (curIdx < s.length()) {
            if (existFlag[s[curIdx]] != -1 &&
                existFlag[s[curIdx]] >= startIdx) {
                length =
                    (length < curIdx - startIdx) ? curIdx - startIdx : length;
                startIdx = existFlag[s[curIdx]] + 1;
                existFlag[s[curIdx]] = curIdx;
            } else
                existFlag[s[curIdx]] = curIdx;

            curIdx++;
        }
        length = (length < curIdx - startIdx) ? curIdx - startIdx : length;
        return length;
    }
};

#endif