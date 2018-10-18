#ifndef __0030_H
#define __0030_H

/**********************************************************
Description:
You are given a string, s, and a list of words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

Example 1:
Input:
    s = "barfoothefoobarman",
    words = ["foo","bar"]
Output: [0,9]

Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.

Example 2:
Input:
    s = "wordgoodstudentgoodword",
    words = ["word","student"]
Output: []
**********************************************************/

#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(s == "" || words.size() == 0)
            return res;

        map<string, int> dict;
        for(int i=0; i<words.size(); i++)
            dict[words[i]] ++;

        int wordNum = words.size(), wordLen = words[0].length();
        for(int leftPtr=0; leftPtr<((int)s.length())-wordLen*wordNum+1; leftPtr++)
        {
            map<string, int> existFlag;
            int wordCnt = 0;
            for(wordCnt=0; wordCnt<wordNum; wordCnt++)
            {
                string curS = s.substr(leftPtr+wordCnt*wordLen, wordLen);
                existFlag[curS] ++;
                if(existFlag[curS] > dict[curS])
                    break;
            }
            if(wordCnt == wordNum)
                res.push_back(leftPtr);
        }
        return res;
    }
};

#endif

