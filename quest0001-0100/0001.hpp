#ifndef __0001_H
#define __0001_H

/*********************************************************************
Description:
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
**********************************************************************/

#include "includes.hpp"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2);
        for(int i=0; i<nums.size(); i++)
        {
            vector<int>::iterator it = find(nums.begin(), nums.end(), target-nums[i]);
            if(it != nums.end() && distance(nums.begin(), it) != i)
            {
                result[0] = i;
                result[1] = distance(nums.begin(), it);
                break;
            }
        }
        return result;
    }
};

#endif