#ifndef __0034_H
#define __0034_H

/**************************************************
Description:
Given an array of integers nums sorted in ascending order, find the starting and
ending position of a given target value. Your algorithm's runtime complexity
must be in the order of O(log n). If the target is not found in the array,
return [-1, -1].

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
**************************************************/

#include "../includes.hpp"

class Solution {
  public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int startIdx = 0, endIdx = nums.size() - 1, terminalIdx = -1;
        vector<int> ret;
        while (startIdx <= endIdx) {
            int midIdx = (endIdx + startIdx) / 2;
            if (nums[midIdx] == target) {
                terminalIdx = midIdx;
                break;
            } else if (nums[midIdx] > target) {
                endIdx = midIdx - 1;
            } else if (nums[midIdx] < target) {
                startIdx = midIdx + 1;
            }
        }

        if (terminalIdx == -1) {
            ret.push_back(-1);
            ret.push_back(-1);
        } else {
            startIdx = terminalIdx;
            endIdx = terminalIdx;
            while (startIdx >= 0 && nums[startIdx] == target) {
                startIdx--;
            }
            while (endIdx <= nums.size() - 1 && nums[endIdx] == target) {
                endIdx++;
            }
            ret.push_back(startIdx + 1);
            ret.push_back(endIdx - 1);
        }
        return ret;
    }
};

#endif
