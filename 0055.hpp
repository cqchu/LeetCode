#ifndef __0055_H
#define __0055_H

/*************************************************
Description:
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.

Example 1:
Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
*************************************************/

#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1)
            return true;
        int curPos = 0;
        while(curPos + nums[curPos] < nums.size()-1) {
            if (nums[curPos] == 0)
                return false;
            int maxStride = 0;
            int nextPos = 0;
            for (int i=1; i<nums[curPos]+1; i++) {
                if (i+nums[curPos+i] >= maxStride) {
                    maxStride = i + nums[curPos+i];
                    nextPos = curPos + i;
                }
            }
            curPos = nextPos;
        }
        return true;
    }
};


#endif