#ifndef __0017_H
#define __0017_H

/**********************************************************
Description:
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

figure: [https://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png]

Example:
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
**********************************************************/

#include "../includes.hpp"

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string st[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> dic(st, st+10);
        vector<string> res;
        if(digits.length() == 0)
            return res;
        res.push_back("");

        for(int i=0; i<digits.length(); i++)    // for each new digit
        {
            int curSize = res.size();
            for(int j=0; j<curSize; j++)     // for each cur res
            {
                string curStr = res[j];
                res[j] += dic[digits[i]-'0'][0];
                for(int k=1; k<dic[digits[i]-'0'].length(); k++)   // for each new char
                    res.push_back(curStr + dic[digits[i]-'0'][k]);
            }
        }
        return res;
    }
};

#endif

