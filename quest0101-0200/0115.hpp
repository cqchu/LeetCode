#ifndef __0115_H
#define __0115_H

/****************************************************
Description:
Given a string S and a string T, count the number of distinct subsequences of S which equals T.
A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
It's guaranteed the answer fits on a 32-bit signed integer.

Example 1:
Input: S = "rabbbit", T = "rabbit"
Output: 3

Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
(The caret symbol ^ means the chosen letters)

rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^

Example 2:
Input: S = "babgbag", T = "bag"
Output: 5

Explanation:
As shown below, there are 5 ways you can generate "bag" from S.
(The caret symbol ^ means the chosen letters)

babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^
****************************************************/

#include "../includes.hpp"

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<unsigned int>> dp(s.size()+1, vector<unsigned int>(t.size()+1, 0));
        for (int i=0; i<s.size(); i++) 
            dp[i][0] = 1;
        for (int i=0; i<s.size(); i++) {
            for (int j=0; j<t.size(); j++) {
                if (j>i)
                    dp[i+1][j+1] = 0;
                else if (s[i] == t[j])
                    dp[i+1][j+1] = dp[i][j] + dp[i][j+1];
                else
                    dp[i+1][j+1] = dp[i][j+1];
            }
        }
        
        // for (int i=0; i<s.size(); i++) {
        //     for (int j=0; j<t.size(); j++) {
        //         cout << dp[i+1][j+1] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[s.size()][t.size()];
    }
};

#endif
