#ifndef __0032_H
#define __0032_H

/***********************************************************
Description:
Suppose an array sorted in ascending order is rotated at some pivot unknown to
you beforehand. (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]). You are
given a target value to search. If found in the array return its index,
otherwise return -1. You may assume no duplicate exists in the array. Your
algorithm's runtime complexity must be in the order of O(log n).

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
***********************************************************/

#include "../includes.hpp"

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int startIdx = 0;
        int endIdx = nums.size() - 1;

        while (endIdx >= startIdx) {
            // cout << startIdx << " " << endIdx << endl;
            int midIdx = (startIdx + endIdx) / 2;
            if (nums[midIdx] == target) {
                return midIdx;
            } else if (nums[midIdx] > nums[startIdx]) { // ascend in the left part
                if (nums[midIdx] >= target && nums[startIdx] <= target) {
                    endIdx = midIdx;
                } else {
                    startIdx = midIdx;
                }
            } else if (nums[midIdx] < nums[startIdx]) { // ascend in the right part
                if (nums[midIdx] <= target && nums[endIdx] >= target) {
                    startIdx = midIdx;
                } else {
                    endIdx = midIdx;
                }
            } else if (nums[midIdx] == nums[startIdx]) {
                if (nums[endIdx] == target)
                    return endIdx;
                else if (nums[startIdx] == target)
                    return startIdx;
                else
                    return -1;
            }
        }
        return -1;
    }
};

#endif
