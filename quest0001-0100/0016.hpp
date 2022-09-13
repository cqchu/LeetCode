#ifndef __0016_H
#define __0016_H

/**********************************************************
Description:
Given an array nums of n integers and an integer target, find three integers in
nums such that the sum is closest to target. Return the sum of the three
integers. You may assume that each input would have exactly one solution.

Example:
Given array nums = [-1, 2, 1, -4], and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
**********************************************************/

#include "../includes.hpp"

class Solution {
  public:
    int threeSumClosest(vector<int> &nums, int target) {
        if (nums.size() < 3)
            return 0;

        int startPtr, endPtr, curPtr = 0;
        int sum = nums[0] + nums[1] + nums[nums.size() - 1];
        sort(nums.begin(), nums.end());

        while (curPtr < nums.size() - 2) {
            startPtr = curPtr + 1;
            endPtr = nums.size() - 1;
            while (startPtr < endPtr) {
                int curSum = nums[curPtr] + nums[startPtr] + nums[endPtr];
                if (abs(curSum - target) < abs(sum - target))
                    sum = curSum;

                if (curSum == target)
                    return curSum;

                if (curSum > target)
                    do {
                        endPtr--;
                    } while (nums[endPtr + 1] == nums[endPtr]);
                if (curSum < target)
                    do {
                        startPtr++;
                    } while (nums[startPtr - 1] == nums[startPtr]);
            }

            do {
                curPtr++;
            } while (nums[curPtr - 1] == nums[curPtr]);
        }
        return sum;
    }
};

#endif
