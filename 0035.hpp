#ifndef __0035_H
#define __0035_H

/************************************************************
Description:
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.

Example 1:
Input: [1,3,5,6], 5
Output: 2

Example 2:
Input: [1,3,5,6], 2
Output: 1

Example 3:
Input: [1,3,5,6], 7
Output: 4

Example 4:
Input: [1,3,5,6], 0
Output: 0

************************************************************/

#include <vector>

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int startIdx=0, endIdx=nums.size()-1;
        int midIdx = 0;
        while (startIdx < endIdx - 1) {
            midIdx = (startIdx + endIdx) / 2;
            if (nums[midIdx] == target) {
                return midIdx;
            }
            else if (nums[midIdx] < target) {
                startIdx = midIdx;
            }
            else if (nums[midIdx] > target) {
                endIdx = midIdx;
            }
            
        }
        if (nums[startIdx] > target)
            return startIdx;
        else if (nums[startIdx] == target)
            return startIdx;
        else if (nums[startIdx] < target && nums[endIdx] > target)
            return startIdx + 1;
        else if (nums[endIdx] == target)
            return endIdx;
        else if (nums[endIdx] < target)
            return endIdx + 1;
        return 0;
    }
};

#endif
