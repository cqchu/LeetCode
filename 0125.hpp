#ifndef __0125_H
#define __0125_H

/****************************************************
Description:
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:
Input: "A man, a plan, a canal: Panama"
Output: true

Example 2:
Input: "race a car"
Output: false
 
Constraints:
s consists only of printable ASCII characters.
****************************************************/

#include "includes.hpp"

class Solution {
public:
    bool isAlphanumeric(char c) {
        return (c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9');
    }
    
    bool isPalindrome(string s) {
        int leftPtr=0, rightPtr=s.size()-1;
        while(leftPtr < rightPtr) {
            if (!isAlphanumeric(s[leftPtr])) {
                leftPtr++;
                continue;
            }
            if (!isAlphanumeric(s[rightPtr])) {
                rightPtr--;
                continue;
            }
                
            char leftChar = s[leftPtr] >= 'a' ? s[leftPtr] : s[leftPtr] + 32;
            char rightChar = s[rightPtr] >= 'a' ? s[rightPtr] : s[rightPtr] + 32;
            // cout << leftChar << " " << rightChar << endl;
            if (leftChar != rightChar)
                return false;
            leftPtr++;
            rightPtr--;
            
        }
        return true;
    }
};

#endif
