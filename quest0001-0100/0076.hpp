#ifndef __0076_H
#define __0076_H

/*******************************************
Description:
Given a string S and a string T, find the minimum window in S which will contain
all the characters in T in complexity O(n).

Example:
    Input: S = "ADOBECODEBANC", T = "ABC"
    Output: "BANC"

Note:
    If there is no such window in S that covers all characters in T, return the
empty string "". If there is such window, you are guaranteed that there will
always be only one unique minimum window in S.
*******************************************/

#include "../includes.hpp"

class Solution {
  public:
    string minWindow(string s, string t) {
        vector<int> hist(128, 0);
        for (char c : t)
            hist[c]++;

        int remaining = t.length();
        int left = 0, right = 0, minStart = 0,
            minLen = numeric_limits<int>::max();
        while (right < s.length()) {
            if (--hist[s[right++]] >= 0)
                remaining--;
            while (remaining == 0) {
                if (right - left < minLen) {
                    minLen = right - left;
                    minStart = left;
                }
                if (++hist[s[left++]] > 0)
                    remaining++;
            }
        }
        return minLen < numeric_limits<int>::max() ? s.substr(minStart, minLen)
                                                   : "";
    }
};

#endif
