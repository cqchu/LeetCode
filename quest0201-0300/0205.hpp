#ifndef __0205_H
#define __0205_H

/*****************************************************
Description:
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving
the order of characters. No two characters may map to the same character, but a
character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true

Example 2:
Input: s = "foo", t = "bar"
Output: false

Example 3:
Input: s = "paper", t = "title"
Output: true

Constraints:
1 <= s.length <= 5 * 10^4
t.length == s.length
s and t consist of any valid ascii character.
*****************************************************/

#include "../includes.hpp"

class Solution {
public:
    bool simple(const std::string &s, const std::string &t) {
        if (s.size() != t.size()) {
            return false;
        }
        if (s.size() <= 1) {
            return true;
        }

        std::unordered_map<char, char> replace;
        for (size_t i = 0; i < s.size(); ++i) {
            auto &&src = s[i];
            auto &&dst = t[i];
            if (replace.find(src) == replace.end()) {
                replace.emplace(src, dst);
            } else {
                if (replace[src] != dst) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isIsomorphic(string s, string t) { return simple(s, t) && simple(t, s); }
};

#endif
