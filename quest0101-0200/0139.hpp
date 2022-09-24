#ifndef __0139_H
#define __0139_H

/****************************************************
Description:
Given a non-empty string s and a dictionary wordDict containing a list of
non-empty words, determine if s can be segmented into a space-separated
sequence of one or more dictionary words.

Note:
The same word in the dictionary may be reused multiple times in the
segmentation. You may assume the dictionary does not contain duplicate words.

Example 1:
Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:
Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen
apple". Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
****************************************************/

#include "../includes.hpp"

class Solution {
public:
    // bool dfs(string &s, unordered_set<string> &dict, int curPos) {
    //     if (curPos >= s.size())
    //         return true;
    //     for (int i=curPos+1; i<=s.size(); i++) {
    //         string fromPos = s.substr(curPos, i-curPos);
    //         if (dict.find(fromPos) != dict.end()) {
    //             if (dfs(s, dict, i) == true)
    //                 return true;
    //         }
    //     }
    //     return false;
    // }
    // bool wordBreak(string s, vector<string>& wordDict) {
    //     unordered_set<string> dict(wordDict.begin(), wordDict.end());
    //     return dfs(s, dict, 0);
    // }

    bool wordBreak(string s, vector<string> &wordDict) {
        if (s.size() == 0)
            return true;
        if (wordDict.size() == 0)
            return false;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size(), false);
        for (int i = s.size() - 1; i >= 0; i--) {
            if (dict.find(s.substr(i)) != dict.end()) {
                dp[i] = true;
                continue;
            }
            for (int j = s.size() - 1; j > i; j--) {
                if (dp[j] == true) {
                    if (dict.find(s.substr(i, j - i)) != dict.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[0];
    }
};

#endif