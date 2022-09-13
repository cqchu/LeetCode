#ifndef __0132_H
#define __0132_H

/****************************************************
Description:
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.

Example:
Input: "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
****************************************************/

#include "../includes.hpp"

// The version 1 is to solve the problem by recurse and enumeration, but the time complexity is too high.
// The reason why our program is slow is that some substrings have been recursed too many times. 
// So in version 2, we have designed a buffer to memorize these substrings which have been recursed.
// Buffer[i] represent the minCut of substr(i, endIdx). This is also can be called the pruning of 
// recurse. At this time, we can find the similar taste with the Dynamic Programming. So in version 3,
// we update our program by DP easily. But we also find at our program, we have compute isPalindrome()
// repeatly too much times, so we also can buffer this information at a similar method, which is shown
// in version 4
// /************************************* version 1 start ***************************************
// class Solution {
// public:
//     bool isPalindrome(string &s, int startIdx, int endIdx) {
//         if (endIdx <= startIdx) {
//             return false;
//         }
//         while (startIdx < endIdx) {
//             if (s[startIdx] != s[endIdx-1]) {
//                 return false;
//             }
//             startIdx ++;
//             endIdx --;
//         }
//         return true;
//     }

//     int recurse(string &s, int startIdx) {
//         int curMin = INT_MAX;
//         if (startIdx >= s.size() - 1)
//             return 0;
//         if (isPalindrome(s, startIdx, s.size())) {
//             return 0;
//         }
//         else {
//             for (int i=startIdx+1; i<s.size(); i++) {
//                 if (isPalindrome(s, startIdx, i)) {
//                     int rhs = recurse(s, i);
//                     curMin = min(curMin, rhs+1);
//                 }
                
//             }
//         }
//         return curMin;
//     }

//     int minCut(string s) {
//         if (s.size() < 2) {
//             return 0;
//         }
//         return recurse(s, 0);
//     }
// };
// *************************************** version 1 end *************************************/

// /************************************* version 2 start ***************************************
// class Solution {
// public:
//     bool isPalindrome(string &s, int startIdx, int endIdx) {
//         if (endIdx <= startIdx) {
//             return false;
//         }
//         while (startIdx < endIdx) {
//             if (s[startIdx] != s[endIdx-1]) {
//                 return false;
//             }
//             startIdx ++;
//             endIdx --;
//         }
//         return true;
//     }

//     int recurse(string &s, vector<int>& buffer, int startIdx) {
//         if (buffer[startIdx] != INT_MAX)
//             return buffer[startIdx];
//         int curMin = INT_MAX;
//         if (startIdx == s.size() - 1) {
//             buffer[startIdx] = 0;
//             return 0;
//         }
//         if (isPalindrome(s, startIdx, s.size())) {
//             buffer[startIdx] = 0;
//             return 0;
//         }
//         else {
//             // cout << startIdx << ": " << s[startIdx] << endl;
//             for (int i=startIdx+1; i<s.size(); i++) {
//                 if (isPalindrome(s, startIdx, i)) {
//                     // int lhs = recurse(s, buffer, startIdx, i);
//                     int rhs = recurse(s, buffer, i);
//                     curMin = min(curMin, rhs+1);
//                 }
//             }
//         }
//         buffer[startIdx] = curMin;
//         return curMin;
//     }

//     int minCut(string s) {
//         if (s.size() < 2) {
//             return 0;
//         }
//         vector<int> buffer(s.size(), INT_MAX);
//         int res = recurse(s, buffer, 0);
//         // for (int i=0; i<s.size(); i++) 
//         //     cout << buffer[i] << " ";
//         // cout << endl;
//         return res;
//     }
// };
// *************************************** version 2 end *************************************/

// /************************************* version 3 start ***************************************
// class Solution {
// public:
//     bool isPalindrome(string &s, int startIdx, int endIdx) {
//         if (endIdx <= startIdx) {
//             return false;
//         }
//         while (startIdx < endIdx) {
//             if (s[startIdx] != s[endIdx-1]) {
//                 return false;
//             }
//             startIdx ++;
//             endIdx --;
//         }
//         return true;
//     }

//     int minCut(string s) {
//         if (s.size() < 2) {
//             return 0;
//         }
//         vector<int> buffer(s.size(), INT_MAX);
//         // convert recurse into dynamic programming
//         for (int i=s.size()-1; i>=0; i--) {
//             if (isPalindrome(s, i, s.size())) {
//                 buffer[i] = 0;
//             }
//             else {
//                 int curMin = INT_MAX;
//                 for (int j=i+1; j<s.size(); j++) {
//                     if (isPalindrome(s, i, j))
//                         curMin = min(curMin, 1+buffer[j]);
//                 }  
//                 buffer[i] = curMin;
//             }
//         }
//         for (int i=0; i<s.size(); i++) 
//             cout << buffer[i] << " ";
//         cout << endl;

//         return buffer[0];
//     }
// };
// *************************************** version 3 end *************************************/

// /************************************* version 4 start ***************************************
class Solution {
public:
    int isPalindromeLazy(string &s, vector<vector<int>>& palin, int startIdx, int endIdx) {
        if (palin[startIdx][endIdx] == INT_MAX) {
            if (endIdx <= startIdx) {
                palin[startIdx][endIdx] = true;
            }
            else if (s[startIdx] != s[endIdx]) {
                palin[startIdx][endIdx] = false;
            }
            else {
                palin[startIdx][endIdx] = isPalindromeLazy(s, palin, startIdx+1, endIdx-1);
            }
        }
        return palin[startIdx][endIdx];
    }

    int minCut(string s) {
        if (s.size() < 2) {
            return 0;
        }

        vector<vector<int>> palin(s.size(), vector<int>(s.size(), INT_MAX));
        vector<int> buffer(s.size(), INT_MAX);

        // convert recurse into dynamic programming
        for (int i=s.size()-1; i>=0; i--) {
            if (isPalindromeLazy(s, palin, i, s.size()-1)) {
                buffer[i] = 0;
            }
            else {
                int curMin = INT_MAX;
                for (int j=i+1; j<s.size(); j++) {
                    if (isPalindromeLazy(s, palin, i, j-1))
                        curMin = min(curMin, 1+buffer[j]);
                }  
                buffer[i] = curMin;
            }
        }
        // for (int i=0; i<s.size(); i++) 
        //     cout << buffer[i] << " ";
        // cout << endl;

        return buffer[0];
    }
};
// *************************************** version 4 end *************************************/

#endif