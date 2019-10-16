#ifndef __0044_H
#define __0044_H

/*************************************************************
Description:
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:
    s could be empty and contains only lowercase letters a-z.
    p could be empty and contains only lowercase letters a-z, and characters like ? or *.

Example 1:
Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.

Example 3:
Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

Example 4:
Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".

Example 5:
Input:
s = "acdcb"
p = "a*c?b"
Output: false
*************************************************************/

class Solution {
public:
    // 构建DP模型，推导DP状态转移函数
    bool isMatch(string s, string p) {
        // 初始化DP矩阵相关设置
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
        dp[0][0] = true;
        for (int i=1; i<dp.size(); i++) {
            dp[i][0] = false;
        }
        for (int i=1; i<dp[0].size(); i++) {
            if (p[i-1] == '*') {
                dp[0][i] = dp[0][i-1];
            }
        }
        
        // 逐个更新状态
        for (int i=0; i<dp.size()-1; i++) {
            for (int j=0; j<dp[i].size()-1; j++) {
                if (p[j]=='?' || p[j]==s[i]) {
                    dp[i+1][j+1] = dp[i][j];
                }
                if (p[j] == '*') {
                    dp[i+1][j+1] = dp[i][j+1] || dp[i+1][j];
                }
            }
        }
        
//         for (int i=0; i<dp.size(); i++) {
//             for (int j=0; j<dp[i].size(); j++) {
//                 cout << dp[i][j] << " ";
//             }
//             cout << endl;
//         }
        
        return dp[s.size()][p.size()];
    }
};

#endif
