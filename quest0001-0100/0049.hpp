#ifndef __0046_H
#define __0046_H

/*************************************************
Description:
Given an array of strings, group anagrams together.

Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:
    All inputs will be in lowercase.
    The order of your output does not matter. 
*************************************************/

#include "../includes.hpp"

// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>> m;
//         for (auto str: strs) {
//             string sortedStr = str;
//             sort(sortedStr.begin(), sortedStr.end(), [](char a, char b) -> bool {return a<b;});
//             if (m.find(sortedStr) == m.end()) {
//                 m.insert(pair<string, vector<string>>(sortedStr, vector<string>(1, str)));
//             }
//             else {
//                 m[sortedStr].push_back(str);
//             }
//         }
//         vector<vector<string>> s;
//         for (auto tmp: m) {
//             s.push_back(tmp.second);
//         }
//         return s;
//     }
// };

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (auto str: strs) {
            int encode[26];
            fill(begin(encode), end(encode), 0);
            for (auto ch: str) {
                encode[ch-'a'] ++;
            }
            char *ckey = reinterpret_cast<char *>(encode);
            string key(ckey, ckey+26*4);
            if (m.find(key) == m.end()) {
                m.insert(pair<string, vector<string>>(key, vector<string>(1, str)));
            }
            else {
                m[key].push_back(str);
            }
        }
        vector<vector<string>> s;
        for (auto tmp: m) {
            s.push_back(tmp.second);
        }
        return s;
    }
};

#endif
