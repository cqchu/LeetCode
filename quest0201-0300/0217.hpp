#ifndef __0217_H
#define __0217_H

/*****************************************************
Description:
Given an integer array nums, return true if any value appears at least twice in the
array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true

Example 2:
Input: nums = [1,2,3,4]
Output: false

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

Constraints:
1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
*****************************************************/

#include "../includes.hpp"

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        std::unordered_set<int> visited;
        for (size_t i = 0; i < nums.size(); ++i) {
            auto val = nums[i];
            if (visited.find(val) != visited.end()) {
                return true;
            } else {
                visited.emplace(val);
            }
        }
        return false;
    }
};

#endif
