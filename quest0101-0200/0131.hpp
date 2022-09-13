#ifndef __0131_H
#define __0131_H

/****************************************************
Description:
Given a string s, partition s such that every substring of the partition is a
palindrome. Return all possible palindrome partitioning of s.

Example:
Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
****************************************************/

#include "../includes.hpp"

class Solution {
  public:
    bool isPalindrome(string &s, int startIdx, int endIdx) {
        if (endIdx < startIdx) {
            return false;
        }
        while (startIdx < endIdx) {
            if (s[startIdx] != s[endIdx - 1]) {
                return false;
            }
            startIdx++;
            endIdx--;
        }
        return true;
    }

    void recurse(vector<vector<string>> &res, vector<string> &vstack, string &s,
                 int depth) {
        if (depth == s.size()) {
            res.push_back(vstack);
        } else {
            for (int i = depth + 1; i <= s.size(); i++) {
                if (isPalindrome(s, depth, i)) {
                    string tmpstr = s.substr(depth, i - depth);
                    vstack.push_back(tmpstr);
                    recurse(res, vstack, s, i);
                    vstack.pop_back();
                }
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> vstack;
        if (s.size() == 0) {
            return res;
        }
        recurse(res, vstack, s, 0);
        return res;
    }
};

#endif