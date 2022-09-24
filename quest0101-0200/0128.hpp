#ifndef __0128_H
#define __0128_H

/****************************************************
Description:
Given an unsorted array of integers, find the length of the longest consecutive
elements sequence. Your algorithm should run in O(n) complexity.

Example:
Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
Therefore its length is 4.
****************************************************/

#include "../includes.hpp"

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        int maxLen = 0;
        unordered_map<int, int> hash; // val -> sequence len

        for (auto x : nums) {
            if (hash[x] == 0) { // not visited this num
                hash[x] = 1;
                int leftPoint = x, rightPoint = x;
                if (hash[x - 1] != 0) // connect with left sequence, find the
                                      // left endpoint of the new sequence
                    leftPoint = x - hash[x - 1];
                if (hash[x + 1] != 0) // connect with right sequence, find the
                                      // right endpoint of the new sequence
                    rightPoint = x + hash[x + 1];
                hash[leftPoint] = rightPoint - leftPoint + 1;
                hash[rightPoint] = rightPoint - leftPoint + 1;
                if (rightPoint - leftPoint + 1 > maxLen)
                    maxLen = rightPoint - leftPoint + 1;
            }
        }
        return maxLen;
    }
};

#endif
