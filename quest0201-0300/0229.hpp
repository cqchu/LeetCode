#ifndef __0229_H
#define __0229_H

/*****************************************************
Description:
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:
Input: nums = [3,2,3]
Output: [3]

Example 2:
Input: nums = [1]
Output: [1]

Example 3:
Input: nums = [1,2]
Output: [1,2]

Constraints:
1 <= nums.length <= 5 * 10^4
-10^9 <= nums[i] <= 10^9

Follow up: Could you solve the problem in linear time and in O(1) space?
*****************************************************/

#include "../includes.hpp"

class Solution {
public:
    // std::vector<int> majorityElement(std::vector<int> &nums) {
    //     if (nums.size() == 0) {
    //         return {};
    //     }

    //     std::unordered_map<int, int> counter;
    //     for (size_t i = 0; i < nums.size(); ++i) {
    //         if (counter.find(nums[i]) == counter.end()) {
    //             counter.emplace(nums[i], 1);
    //         } else {
    //             counter[nums[i]] += 1;
    //         }
    //     }

    //     std::vector<int> ret;
    //     for (auto &&item : counter) {
    //         if (static_cast<double>(item.second) / nums.size() > (1.0 / 3.0)) {
    //             ret.emplace_back(item.first);
    //         }
    //     }
    //     return ret;
    // }
    std::vector<int> majorityElement(std::vector<int> &nums) {
        if (nums.size() == 0) {
            return {};
        }
        if (nums.size() == 1) {
            return {nums[0]};
        }
        int candidate1 = nums[0], count1 = 1;
        int candidate2 = -1, count2 = 0;
        size_t start = 0;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] != candidate1) {
                candidate2 = nums[i];
                count2 = 1;
                start = i;
                break;
            } else {
                count1 += 1;
            }
        }

        if (count2 == 0) {
            return {candidate1};
        }

        for (size_t i = start + 1; i < nums.size(); ++i) {
            if (nums[i] == candidate1) {
                count1 += 1;
            } else if (nums[i] == candidate2) {
                count2 += 1;
            } else if (count1 == 0) {
                candidate1 = nums[i];
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = nums[i];
                count2 = 1;
            } else {
                count1 -= 1;
                count2 -= 1;
            }
        }

        count1 = 0;
        count2 = 0;

        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] == candidate1) {
                count1 += 1;
            } else if (nums[i] == candidate2) {
                count2 += 1;
            }
        }

        std::vector<int> ret;
        if (static_cast<double>(count1) / nums.size() > 1.0 / 3) {
            ret.emplace_back(candidate1);
        }
        if (static_cast<double>(count2) / nums.size() > 1.0 / 3) {
            ret.emplace_back(candidate2);
        }
        return ret;
    }
};

#endif
