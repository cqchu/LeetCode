#ifndef __0209_H
#define __0209_H

/*****************************************************
Description:
Given an array of positive integers nums and a positive integer target, return the
minimal length of a subarray whose sum is greater than or equal to target. If there is
no such subarray, return 0 instead.

Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

Constraints:
1 <= target <= 10^9
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^4
*****************************************************/

#include "../includes.hpp"

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        size_t minimal_len = INT_MAX;
        int cur_sum = 0;
        for (size_t left = 0, right = 1; right <= nums.size(); ++right) {
            cur_sum += nums[right - 1];
            while (cur_sum >= target) {
                minimal_len = std::min(minimal_len, right - left);
                cur_sum -= nums[left];
                ++left;
            }

            if (minimal_len == 1) {
                return 1;
            }
        }
        return minimal_len == INT_MAX ? 0 : minimal_len;
    }
};

#endif
