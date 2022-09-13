#ifndef __0027_H
#define __0027_H

/**********************************************************
Description:
Given an array nums and a value val, remove all instances of that value in-place and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.
**********************************************************/

#include "includes.hpp"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int originLen = nums.size();
        if(originLen == 0)
            return 0;

        int rmCnt = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(val == nums[i])
                rmCnt ++;
            else
                nums[i-rmCnt] = nums[i];
        }
        nums.resize(originLen-rmCnt);
        return originLen - rmCnt;
    }
};

#endif

