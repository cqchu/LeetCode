#ifndef __0179_H
#define __0179_H

/*****************************************************
Description:
Given a list of non-negative integers nums, arrange them such that they form
the largest number and return it. Since the result may be very large, so you
need to return a string instead of an integer.

Example 1:
Input: nums = [10,2]
Output: "210"

Example 2:
Input: nums = [3,30,34,5,9]
Output: "9534330"

Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 10^9
*****************************************************/

#include "../includes.hpp"

class Solution {
public:
    string largestNumber(vector<int> &nums) {
        if (std::all_of(nums.begin(), nums.end(),
                        [](int num) -> bool { return num == 0; })) {
            return {"0"};
        }

        std::vector<std::string> strs(nums.size());
        std::transform(
            nums.begin(), nums.end(), strs.begin(),
            [](int num) -> std::string { return std::to_string(num); });

        std::sort(strs.begin(), strs.end(),
                  [](const std::string &lhs, const std::string &rhs) {
                      auto l1 = lhs + rhs;
                      auto l2 = rhs + lhs;
                      return l1 > l2;
                  });
        std::string ret;
        for (auto &&str : strs) {
            ret += str;
        }
        return ret;
    }
};

#endif
