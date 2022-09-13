#ifndef __0136_H
#define __0136_H

/****************************************************
Description:
Given a non-empty array of integers, every element appears twice except for one.
Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it
without using extra memory?

Example 1:
Input: [2,2,1]
Output: 1
****************************************************/

#include "../includes.hpp"

class Solution {
  public:
    // int singleNumber(vector<int>& nums) {
    //     if (nums.size() == 0)
    //         return 0;
    //     unordered_set<int> uos;
    //     for (int num: nums) {
    //         unordered_set<int>::iterator it = uos.find(num);
    //         if (it == uos.end())
    //             uos.insert(num);
    //         else
    //             uos.erase(it);
    //     }
    //     return *uos.begin();
    // }
    int singleNumber(vector<int> &nums) {
        if (nums.size() == 0)
            return 0;
        int res = 0;
        for (int num : nums) {
            res = res ^ num;
        }
        return res;
    }
};

#endif