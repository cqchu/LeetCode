#ifndef __0097_H
#define __0097_H

/****************************************************
Description:
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example 1:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true

Example 2:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
****************************************************/

#include "../includes.hpp"

class Solution {
  public:
    /*
    bool recurse(string &s1, string &s2, string &s3, int ptr1, int ptr2, int
    ptr3)
    {
        // some stop condition
        if (ptr1 == s1.size() && ptr2 == s2.size() && ptr3 == s3.size())
            return true;
        if (ptr3 == s3.size() && (ptr1 < s1.size() || ptr2 < s2.size()))
            return false;

        // recurse
        bool flag = false;
        if (ptr1 < s1.size() && s1[ptr1] == s3[ptr3])
            flag = recurse(s1, s2, s3, ptr1+1, ptr2, ptr3+1);
        if (ptr2 < s2.size() && s2[ptr2] == s3[ptr3])
            flag = flag || recurse(s1, s2, s3, ptr1, ptr2+1, ptr3+1);
        return flag;
    }
    */
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;

        // recurse-based method TLE
        // int ptr1 = 0, ptr2 = 0, ptr3 = 0;
        // return recurse(s1, s2, s3, ptr1, ptr2, ptr3);

        // Use DP - 2D version
        int m = s1.size(), n = s2.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // initialize the dp matrix
        dp[0][0] = true; // dp[i][j] represent the first-(i+j) char of
                         // s3 can be formed by the interleaving of
                         // first-i char of s1 and first-j char of s2

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (j > 0 && dp[i][j - 1] && s2[j - 1] == s3[i + j - 1])
                    dp[i][j] = true;
                if (i > 0 && dp[i - 1][j] && s1[i - 1] == s3[i + j - 1])
                    dp[i][j] = true;
            }
        }

        // for (int i=0; i<=m; i++) {
        //     for (int j=0; j<=n; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[m][n];
    }
};

#endif