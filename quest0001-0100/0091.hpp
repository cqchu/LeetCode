#ifndef __0091_H
#define __0091_H

/**********************************************
Description:
A message containing letters from A-Z is being encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:
Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).

Example 2:
Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
**********************************************/

#include "../includes.hpp"

class Solution {
public:
    /*
    // Recurse method, but TLE, we use DP to optimize it, which is similar to problem 0050
    int recurse(string s) {
        if (s[0] == '0')
            return 0;
        if (s.size() == 0)
            return 1;
        if (s.size() == 1 && s[0] != '0')
            return 1;
        
        int cnt = recurse(s.substr(1));
        if ((s[0]-'0')*10+s[1]-'0' <= 26)
            cnt = cnt + recurse(s.substr(2));
        return cnt;
    }
    */
    
    int numDecodings(string s) {
        // return recurse(s);
        if (s.size() == 0)
            return 1;
        if (s[0] == '0')
            return 0;
        if (s.size() == 1)
            return 1;
        
        vector<int> dp(s.size()+1, 1);      // we also can reduce the length of DP vector to 2 (constant space) 
        for (int i=s.size()-1; i>=0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
            }
            else {
                dp[i] = dp[i+1];
                if (i < s.size()-1 && (s[i]-'0')*10+s[i+1]-'0' <= 26)
                    dp[i] += dp[i+2];
            }    
        }
        // for (int i=0; i<s.size()+1; i++)
        //     cout << dp[i] << " ";
        // cout << endl;
        return dp[0];
    }
};

#endif