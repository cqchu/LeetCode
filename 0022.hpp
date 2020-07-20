#ifndef __0022_H
#define __0022_H

/**********************************************************
Description:
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
**********************************************************/

#include "includes.hpp"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n == 0)
            return res;
        if(n == 1)
        {
            res.push_back("()");
            return res;
        }
        
        set<string> stmp;
        for(int i=1; i<n; i++)
        {
            //res = CartesianProduct(generateParenthesis(i), generateParenthesis(n - i));
            vector<string> left, right;
            left = generateParenthesis(i);
            right = generateParenthesis(n - i);
        
            for(int j=0; j<left.size(); j++)
                for(int k=0; k<right.size(); k++)
                {
                    string s = left[j] + right[k];
                    stmp.insert(s);
                }

            if(i == 1)
            {
                for(int k=0; k<right.size(); k++)
                {
                    string s = "(" + right[k] + ")";
                    stmp.insert(s);
                }
            }
        }

        for(set<string>::iterator it=stmp.begin(); it!=stmp.end(); it++)
            res.push_back(*it);
        return res;
    }
};

#endif

