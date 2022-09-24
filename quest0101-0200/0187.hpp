#ifndef __0187_H
#define __0187_H

/*****************************************************
Description:
The DNA sequence is composed of a series of nucleotides abbreviated as 'A',
'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long
sequences (substrings) that occur more than once in a DNA molecule. You may
return the retwer in any order.

Example 1:
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]

Example 2:
Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]

Constraints:
1 <= s.length <= 10^5
s[i] is either 'A', 'C', 'G', or 'T'.
*****************************************************/

#include "../includes.hpp"

class Solution {
public:
    // vector<string> findRepeatedDnaSequences(string s) {
    //     if (s.size() < 10) {
    //         return {};
    //     }
    //     std::unordered_map<std::string, size_t> counter;
    //     for (size_t i = 0; i < s.size() - 9; ++i) {
    //         std::string sub = s.substr(i, 10);
    //         if (counter.find(sub) == counter.end()) {
    //             counter[sub] = 1;
    //         } else {
    //             counter[sub]++;
    //         }
    //     }

    //     LOG_MAP(counter);
    //     std::vector<std::string> ret;
    //     for (auto &&kv : counter) {
    //         if (kv.second > 1) {
    //             ret.emplace_back(kv.first);
    //         }
    //     }
    //     return ret;
    // }

    int getVal(char c) {
        if (c == 'A')
            return 0;
        if (c == 'C')
            return 1;
        if (c == 'G')
            return 2;
        return 3;
    }

    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10)
            return {};

        std::vector<std::string> ret;

        // because echo character in str have four status (A, T, C, G), so a
        // 10-letter-long substr has 4^10=2^20 status, so we set bitset with len
        // 2^20 to record all status in str
        bitset<1 << 20> status, visited;
        int val = 0;
        for (int i = 0; i < 10; i++) {
            // because echo char have four status, so we << 2 rather than << 1
            val = (val << 2) | getVal(s[i]);
        }
        status.set(val);
        int mask = (1 << 20) - 1;
        for (int i = 10; i < s.size(); i++) {
            // we only SHIFT RIGHT 2 bit for each new char
            val = ((val << 2) & mask) | getVal(s[i]);
            if (visited[val]) // if visited, that have been inserted to ret
                continue;
            if (status[val]) {
                ret.push_back(s.substr(i - 10 + 1, 10));
                visited.set(val);
            } else
                status.set(val);
        }
        return ret;
    }
};

#endif
