#ifndef __0058_H
#define __0058_H

/*************************************************
Description:
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
If the last word does not exist, return 0.
Note: A word is defined as a character sequence consists of non-space characters only.

Example:
Input: "Hello World"
Output: 5
*************************************************/

#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        bool findword = false;
        for (int i=s.size()-1; i>=0; i--) {
            if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
                len = len + 1;
                findword = true;
            }
            else if (s[i] == ' ' && findword == true){
                break;
            }
        }
        return len;
    }
};


#endif
