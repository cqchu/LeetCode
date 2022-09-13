#ifndef __0043_H
#define __0043_H

/*******************************************************
Description:
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"

Note:
    The length of both num1 and num2 is < 110.
    Both num1 and num2 contain only digits 0-9.
    Both num1 and num2 do not contain any leading zero, except the number 0 itself.
    You must not use any built-in BigInteger library or convert the inputs to integer directly.
********************************************************/

#include "../includes.hpp"

class Solution {
public:
    string add(const string num1, const string num2) {
        int maxLen = max(num1.size(), num2.size());
        string res(maxLen+1, '0');
        int carry = 0;
        for (int i=0; i<maxLen; i++) {
            int nl = num1.size()>i ? num1[num1.size()-i-1]-'0' : 0; 
            int nr = num2.size()>i ? num2[num2.size()-i-1]-'0' : 0;
            // cout << nl << " + " << nr << endl;
            int tmpRes = nl + nr + carry;
            int low = tmpRes % 10;
            carry = tmpRes / 10;
            res[maxLen-i] = low + '0';   
        }
        if (carry != 0) {
            res[0] = carry + '0';
        }
        int zeroCnt = 0;
        for (; zeroCnt < res.size()-1; zeroCnt++) {
            if (res[zeroCnt] != '0')
                break;
        }
        res = res.substr(zeroCnt, res.size());
        cout << res << " = " << num1 << " + " << num2 << endl;
        return res;
    }
    
    string multiplySingle(const string num1, const char num2) {
        int maxLen = num1.size();
        string res(maxLen+1, '0');
        int carry = 0;
        for (int i=0; i<maxLen; i++) {
            int nl = num1.size()>i ? num1[num1.size()-i-1]-'0' : 0; 
            int nr = num2 - '0';
            int tmpRes = nl * nr + carry;
            int low = tmpRes % 10;
            carry = tmpRes / 10;
            res[maxLen-i] = low + '0';   
        }
        if (carry != 0) {
            res[0] = carry + '0';
        }
        int zeroCnt = 0;
        for (; zeroCnt < res.size()-1; zeroCnt++) {
            if (res[zeroCnt] != '0')
                break;
        }
        res = res.substr(zeroCnt, res.size());
        cout << res.size() << ": "<< res << " = " << num1 << " * " << num2 << endl;
        return res;
    }

    string multiply(const string num1, const string num2) {
        string res = "0";
        for (int i=0; i<num2.size(); i++) {
            string mulRes = multiplySingle(num1, num2[num2.size()-1-i]);
            string tailZero(i, '0');
            mulRes = mulRes + tailZero;
            res = add(res, mulRes);
        }
        return res;
    }
};

#endif
