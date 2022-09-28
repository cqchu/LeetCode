#ifndef __0065_H
#define __0065_H

/*******************************************
Description:
Validate if a given string can be interpreted as a decimal number.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false

Note: It is intended for the problem statement to be ambiguous. You should
gather all requirements up front before implementing one. However, here is a
list of characters that can be in a valid decimal number: Numbers 0-9 Exponent
- "e" Positive/negative sign - "+"/"-" Decimal point - "."

Of course, the context of these characters also matters in the input.
*******************************************/

#include "../includes.hpp"

class Solution {
public:
    bool maybeValid(char ch) {
        return (ch >= '0' && ch <= '9') || ch == '+' || ch == '-' || ch == 'e' ||
               ch == '.';
    }

    bool isNumber(string s) {
        int curPos = 0;
        bool baseSignFlag = false, baseFlag = false, pointFlag = false, expFlag = false,
             powSignFlag = false, powFlag = false;

        int start = 0, end = s.size();
        for (start = 0; start < s.size() && s[start] == ' '; start++)
            ;
        for (end = s.size(); end > 0 && s[end - 1] == ' '; end--)
            ;
        s = s.substr(start, end - start);

        for (; curPos < s.size(); curPos++) {
            if (!maybeValid(s[curPos]))
                return false;
            if (s[curPos] == '+' || s[curPos] == '-') {
                if (baseSignFlag == false)
                    baseSignFlag = true;
                else
                    return false;
            } else if (s[curPos] >= '0' && s[curPos] <= '9') {
                baseSignFlag = true;
                break;
            } else if (s[curPos] == '.') {
                baseSignFlag = true;
                break;
            } else
                return false;
        }

        for (; curPos < s.size(); curPos++) {
            if (!maybeValid(s[curPos]))
                return false;
            if (s[curPos] >= '0' && s[curPos] <= '9')
                baseFlag = true;
            else if (s[curPos] == '.' && pointFlag == false)
                pointFlag = true;
            else if (s[curPos] == 'e') {
                pointFlag = true;
                expFlag = true;
                curPos++;
                break;
            } else
                return false;
        }
        if (curPos == s.size()) {
            pointFlag = true;
        }

        cout << baseSignFlag << baseFlag << pointFlag << expFlag << powSignFlag
             << powFlag << endl;
        if (curPos == s.size() && baseSignFlag && baseFlag && pointFlag && !expFlag &&
            !powSignFlag && !powFlag)
            return true;

        for (; curPos < s.size(); curPos++) {
            if (!maybeValid(s[curPos]))
                return false;
            if (s[curPos] == '+' || s[curPos] == '-') {
                if (powSignFlag == false)
                    powSignFlag = true;
                else
                    return false;
            } else if (s[curPos] >= '0' && s[curPos] <= '9') {
                powSignFlag = true;
                break;
            } else
                return false;
        }

        cout << baseSignFlag << baseFlag << pointFlag << expFlag << powSignFlag
             << powFlag << endl;

        for (; curPos < s.size(); curPos++) {
            if (!maybeValid(s[curPos]))
                return false;
            if (s[curPos] >= '0' && s[curPos] <= '9')
                powFlag = true;
            else
                return false;
        }
        cout << baseSignFlag << baseFlag << pointFlag << expFlag << powSignFlag
             << powFlag << endl;

        return baseSignFlag && baseFlag && pointFlag && expFlag && powSignFlag &&
               powFlag;
    }
};

#endif
