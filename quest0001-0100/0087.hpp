#ifndef __0087_H
#define __0087_H

/**********************************************
Description:
Given a string s1, we may represent it as a binary tree by partitioning it to
two non-empty substrings recursively. Below is one possible representation of
s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t

To scramble the string, we may choose any non-leaf node and swap its two
children. For example, if we choose the node "gr" and swap its two children, it
produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t

We say that "rgeat" is a scrambled string of "great".
Similarly, if we continue to swap the children of nodes "eat" and "at", it
produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a

We say that "rgtae" is a scrambled string of "great".
Given two strings s1 and s2 of the same length, determine if s2 is a scrambled
string of s1.

Example 1:
Input: s1 = "great", s2 = "rgeat"
Output: true

Example 2:
Input: s1 = "abcde", s2 = "caebd"
Output: false
**********************************************/

#include "../includes.hpp"

class Solution {
public:
    bool recurse(string str, int startPos, string &s2) {
        if (str.size() == 1) {
            if (str[0] == s2[startPos])
                return true;
            else
                return false;
        }

        vector<int> table1(26, 0), table2(26, 0);
        for (int i = 0; i < str.size(); i++)
            table1[str[i] - 'a']++;
        for (int i = 0; i < str.size(); i++)
            table2[s2[i + startPos] - 'a']++;
        for (int i = 0; i < 26; i++)
            if (table1[i] != table2[i])
                return false;

        for (int i = 1; i < str.size(); i++) {
            if ((recurse(str.substr(0, i), startPos, s2) &&
                 recurse(str.substr(i), startPos + i, s2)) ||
                (recurse(str.substr(i), startPos, s2) &&
                 recurse(str.substr(0, i), startPos + str.size() - i, s2)))
                return true;
        }
        return false;
    }

    bool isScramble(string s1, string s2) { return recurse(s1, 0, s2); }
};
#endif