#ifndef __0093_H
#define __0093_H

/****************************************************
Description:
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:
Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
****************************************************/

#include "includes.hpp"

class Solution {
public:
    void recurse(string &s, vector<string> &res, string& prefix, int pos, int depth) {
        if (depth == 4) {
            if (s.size()-pos > 3 || s.size()-pos == 0) return;
            if (s.size()-pos != 1 && s[pos] == '0') return;
            if (atoi(s.substr(pos).c_str()) > 255) return;
            res.push_back(prefix + s.substr(pos));
        }
        else {
            if (s.size() - pos > 1) {
                prefix = prefix + s.substr(pos, 1) + ".";
                recurse(s, res, prefix, pos+1, depth+1);
                prefix = prefix.substr(0, prefix.size()-2);
            }
 
            if (s.size() - pos > 2 && s[pos] != '0') {
                prefix = prefix + s.substr(pos, 2) + ".";
                recurse(s, res, prefix, pos+2, depth+1);
                prefix = prefix.substr(0, prefix.size()-3);
            }
            
            if (s.size() - pos  > 3 && s[pos] != '0' && atoi(s.substr(pos, 3).c_str()) <= 255) {
                prefix = prefix + s.substr(pos, 3) + ".";
                recurse(s, res, prefix, pos+3, depth+1);
                prefix = prefix.substr(0, prefix.size()-4);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string prefix = "";
        recurse(s, res, prefix, 0, 1);
        return res;
    }
};

#endif