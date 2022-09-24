#ifndef __0041_H
#define __0041_H

/************************************************
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:
Input: [1,2,0]
Output: 3

Example 2:
Input: [3,4,-1,1]
Output: 2

Example 3:
Input: [7,8,9,11,12]
Output: 1

Note:
Your algorithm should run in O(n) time and uses constant extra space.
************************************************/

#include "../includes.hpp"

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0 && nums[i] < nums.size() && nums[i] != i + 1) {
                int tmp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                if (tmp != nums[i]) { // ��ֹ�����ظ�����
                    nums[i] = tmp;
                    i--;
                }
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return nums.size() + 1;
    }
};

#endif
