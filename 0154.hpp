#ifndef __0154_H
#define __0154_H

/****************************************************
Description:
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.
The array may contain duplicates.

Example 1:
Input: [1,3,5]
Output: 1

Example 2:
Input: [2,2,2,0,1]
Output: 0

Note:
This is a follow up problem to Find Minimum in Rotated Sorted Array.
Would allow duplicates affect the run-time complexity? How and why?
****************************************************/

#include "includes.hpp"

class Solution {
public:
    int recurse(int startIdx, int endIdx, vector<int>& nums) {
        while (nums[startIdx] == nums[endIdx] && startIdx < endIdx) {
            ++startIdx;
        }
        if (endIdx - startIdx <= 1)
            return min(nums[startIdx], nums[endIdx]);
        
        int midIdx = startIdx + (endIdx + 1 - startIdx)/2;
        // cout << startIdx << " " << midIdx << " " << endIdx << endl;
        if (nums[midIdx] == nums[startIdx])
            return recurse(midIdx, endIdx, nums);
        else if (nums[midIdx] == nums[endIdx])
            return recurse(startIdx, midIdx, nums);
        else if (nums[midIdx] > nums[startIdx] && nums[midIdx] > nums[endIdx])
            return recurse(midIdx, endIdx, nums);
        else if (nums[midIdx] < nums[startIdx] && nums[midIdx] < nums[endIdx])
            return recurse(startIdx, midIdx, nums);
        else
            return recurse(startIdx, midIdx, nums);
    }
    
    int findMin(vector<int>& nums) {
        return recurse(0, nums.size()-1, nums);
    }
};

#endif