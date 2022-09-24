#ifndef __0140_H
#define __0140_H

/****************************************************
Description:
Given a non-empty string s and a dictionary wordDict containing a list of
non-empty words, add spaces in s to construct a sentence where each word is a
valid dictionary word. Return all such possible sentences.

Note:
The same word in the dictionary may be reused multiple times in the
segmentation. You may assume the dictionary does not contain duplicate words.

Example 1:
Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]

Example 2:
Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.

Example 3:
Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]
****************************************************/

#include "../includes.hpp"

class Solution {
public:
    bool justify(string s, vector<string> &wordDict) {
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

    void dfs(string &s, unordered_set<string> &dict, vector<string> &res,
             vector<string> &stk, int curPos) {
        if (curPos >= s.size() && stk.size() != 0) {
            string s = stk[0];
            for (int i = 1; i < stk.size(); i++) {
                s.append(" ");
                s.append(stk[i]);
            }
            res.push_back(s);
            return;
        }
        for (int i = curPos + 1; i <= s.size(); i++) {
            string fromPos = s.substr(curPos, i - curPos);
            if (dict.find(fromPos) != dict.end()) {
                stk.push_back(fromPos);
                dfs(s, dict, res, stk, i);
                stk.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string> &wordDict) {
        vector<string> res, stk;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        if (justify(s, wordDict))
            dfs(s, dict, res, stk, 0);
        return res;
    }
};

#endif