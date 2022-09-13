#ifndef __0137_H
#define __0137_H

/****************************************************
Description:
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:
Input: [2,2,3,2]
Output: 3

Example 2:
Input: [0,1,0,1,0,1,99]
Output: 99
****************************************************/

#include "includes.hpp"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        const int n = nums.size();
        
        int ones = 0;
        int twos = 0;
        
        for(int i = 0; i < n; i++){
            ones ^= nums[i];
            ones &= ~twos;
            twos ^= nums[i];
            twos &= ~ones;
        }
        
        return ones;
    }
};

#endif