#ifndef __0018_H
#define __0018_H

/**********************************************************
Description:
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
The solution set must not contain duplicate quadruplets.

Example:
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
**********************************************************/

#include "includes.hpp"

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        if(nums.size() < 4)
            return res;
        sort(nums.begin(), nums.end());
        int firstPtr=0, secondPtr=0, startPtr=0, endPtr=0;
        while(firstPtr<nums.size()-3)
        {
            secondPtr=firstPtr+1;
            while(secondPtr<nums.size()-2)
            {
                startPtr = secondPtr + 1;
                endPtr = nums.size() - 1;
                while(startPtr < endPtr)
                {
                    if(nums[firstPtr] + nums[secondPtr] + nums[startPtr] + nums[endPtr] > target)
                    {
                        do {
                            endPtr --;
                        } while(nums[endPtr+1] == nums[endPtr]);
                    }
                    else if(nums[firstPtr] + nums[secondPtr] + nums[startPtr] + nums[endPtr] < target)
                    {
                        do {
                            startPtr ++;
                        } while(nums[startPtr-1] == nums[startPtr]);
                    }
                    else
                    {
                        int tmp[] = {nums[firstPtr], nums[secondPtr], nums[startPtr], nums[endPtr]};
                        vector<int> vtmp(tmp, tmp+4);
                        res.push_back(vtmp);
                        do {
                            endPtr --;
                        } while(nums[endPtr+1] == nums[endPtr]);
                        do {
                            startPtr ++;
                        } while(nums[startPtr-1] == nums[startPtr]);
                    }
                }
                do {
                    secondPtr ++;
                } while(nums[secondPtr-1] == nums[secondPtr]);
            }
            do {
                firstPtr ++;
            } while(nums[firstPtr-1] == nums[firstPtr]);
        }
        return res;
    }
};

#endif

