#ifndef __0014_H
#define __0014_H

/**********************************************************
Description:
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
**********************************************************/

#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        for(int idx=0; strs.size() > 0; idx++)
        {
            if(strs[0].length() <= idx)
                break;

            bool flag = true;
            for(int i=1; i<strs.size(); i++)
            {
                if(strs[i].length() <= idx || strs[i][idx] != strs[0][idx])
                {
                    flag = false;
                    break;
                }
            }
            if(flag == false)
                break;
            prefix = prefix + strs[0][idx];
        }
        return prefix;
    }
};

#endif

