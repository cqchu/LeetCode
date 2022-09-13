#ifndef __0026_H
#define __0026_H

/**********************************************************
Description:
Given a sorted array nums, remove the duplicates in-place such that each element
appear only once and return the new length. Do not allocate extra space for
another array, you must do this by modifying the input array in-place with O(1)
extra memory.
**********************************************************/

#include "../includes.hpp"

class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() == 0)
            return 0;

        int allLen = 1;
        int pre = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (pre != nums[i]) {
                nums[allLen] = nums[i];
                allLen++;
                pre = nums[i];
            }
        }

        nums.resize(allLen);
        return allLen;
    }
};

#endif
