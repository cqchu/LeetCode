#ifndef __0213_H
#define __0213_H

/*****************************************************
Description:
You are a professional robber planning to rob houses along a street. Each house has a
certain amount of money stashed. All houses at this place are arranged in a circle. That
means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a
security system connected, and it will automatically contact the police if two adjacent
houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the
maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
because they are adjacent houses.

Example 2:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 3:
Input: nums = [1,2,3]
Output: 3

Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 1000
*****************************************************/

#include "../includes.hpp"
class Solution {
public:
    int rob(vector<int> &nums) {
        size_t len = nums.size();

        if (len <= 3) {
            int ret = INT_MIN;
            for (size_t i = 0; i < len; ++i) {
                ret = std::max(nums[i], ret);
            }
            return ret;
        }

        std::vector<int> dp1(len, 0);
        std::vector<int> start1(len, 0);

        dp1[0] = nums[0];
        start1[0] = 0;
        dp1[1] = std::max(nums[0], nums[1]);
        start1[1] = nums[0] > nums[1] ? 0 : 1;
        for (size_t i = 2; i < len; ++i) {
            dp1[i] = std::max(dp1[i - 1], dp1[i - 2] + nums[i]);
            start1[i] =
                (dp1[i - 2] + nums[i]) > dp1[i - 1] ? start1[i - 2] : start1[i - 1];
        }

        std::vector<int> dp2(len, 0);
        std::vector<int> start2(len, 0);
        dp2[1] = nums[1];
        start2[1] = 1;
        dp2[2] = std::max(nums[1], nums[2]);
        start2[2] = nums[1] > nums[2] ? 1 : 2;

        for (size_t i = 2; i < len; ++i) {
            dp2[i] = std::max(dp2[i - 1], dp2[i - 2] + nums[i]);
            start2[i] =
                (dp2[i - 2] + nums[i]) > dp2[i - 1] ? start2[i - 2] : start2[i - 1];
        }

        if (start1[len - 1] == 0) {
            return std::max(dp1[len - 2], dp2[len - 1]);
        }

        return dp1[len - 1];
    }
};

#endif
