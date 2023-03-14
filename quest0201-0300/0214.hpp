#ifndef __0214_H
#define __0214_H

/*****************************************************
Description:
You are given a string s. You can convert s to a
palindrome by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

Example 1:
Input: s = "aacecaaa"
Output: "aaacecaaa"

Example 2:
Input: s = "abcd"
Output: "dcbabcd"

Constraints:
0 <= s.length <= 5 * 10^4
s consists of lowercase English letters only.
*****************************************************/

#include "../includes.hpp"

// class Solution {
// public:
//     bool is_good_odd(const std::string &s, int idx) {
//         for (int i=0; idx-i>=0 && idx+i < s.size(); ++i) {
//             if (s[idx-i] != s[idx+i]) {
//                 return false;
//             }
//         }
//         return true;
//     }
//     bool is_good_even(const std::string &s, int idx) {
//         if (idx >= s.size() / 2) {
//             return false;
//         }
//         for (int i=0; idx-i>=0 && idx+i+1 < s.size(); ++i) {
//             if (s[idx-i] != s[idx+i+1]) {
//                 return false;
//             }
//         }
//         return true;
//     }
//     std::string complete_even(const std::string &s, size_t idx) {
//         size_t len_s = s.size();
//         size_t new_len = (len_s - idx - 2) * 2 + 2;
//         std::string ret(new_len, ' ');
//         for (size_t i=0; i < new_len/2; ++i) {
//             ret[i] = s[len_s - i - 1];
//         }
//         for (size_t i=0; i < new_len/2; ++i) {
//             ret[new_len-i-1] = s[len_s - i - 1];
//         }
//         return ret;
//     }
//     std::string complete_odd(const std::string &s, size_t idx) {
//         size_t len_s = s.size();
//         size_t new_len = (len_s - idx - 1) * 2 + 1;
//         std::string ret(new_len, ' ');
//         for (size_t i=0; i < new_len/2 + 1; ++i) {
//             ret[i] = s[len_s - i - 1];
//         }
//         for (size_t i=0; i < new_len/2; ++i) {
//             ret[new_len-i-1] = s[len_s-i-1];
//         }
//         return ret;
//     }

//     string shortestPalindrome(string s) {
//         if (s.size() <= 1)
//             return s;

//         size_t start_idx = (s.size()-1) / 2;
//         for (int idx = start_idx; idx >= 0; --idx) {
//             if (is_good_even(s, idx)) {
//                 return complete_even(s, idx);
//             }
//             if (is_good_odd(s, idx)) {
//                 return complete_odd(s, idx);
//             }
//         }
//         return {};
//     }
// };

class Solution {
public:
    string shortestPalindrome(string s) {
        ios_base::sync_with_stdio(0);
        string rev = s;
        reverse(rev.begin(), rev.end());
        int n = s.size();
        s = s + "#" + rev;
        vector<int> lps(2 * n + 1, 0);
        for (int i = 1; i <= 2 * n; i++) {
            int j = lps[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = lps[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            lps[i] = j;
        }
        int diff = n - lps[2 * n];
        while (diff) {
            rev.push_back(rev[diff - 1]);
            diff--;
        }
        return rev;
    }
};

#endif
