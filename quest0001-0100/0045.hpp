#ifndef __0045_H
#define __0045_H

/*************************************************
Description:
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.

Example:
Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.

Note:
You can assume that you can always reach the last index.
*************************************************/

#include "../includes.hpp"

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int curPos = 0, stepCnt=0;
        while(curPos + nums[curPos] < nums.size()-1) {
            int maxStride = 0;
            int nextPos = 0;
            for (int i=1; i<nums[curPos]+1; i++) {
                if (i+nums[curPos+i] > maxStride && nums[curPos+i] != 0) {
                    maxStride = i + nums[curPos+i];
                    nextPos = curPos + i;
                }
            }
            curPos = nextPos;
            stepCnt ++;
        }
        return stepCnt+1;
    }
};

#endif