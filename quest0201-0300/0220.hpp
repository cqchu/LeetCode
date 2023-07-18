#ifndef __0220_H
#define __0220_H

/*****************************************************
Description:
You are given an integer array nums and two integers indexDiff and valueDiff.
Find a pair of indices (i, j) such that:
* i != j,
* abs(i - j) <= indexDiff,
* abs(nums[i] - nums[j]) <= valueDiff, and
Return true if such pair exists or false otherwise.

Example 1:
Input: nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
Output: true
Explanation: We can choose (i, j) = (0, 3).
We satisfy the three conditions:
i != j --> 0 != 3
abs(i - j) <= indexDiff --> abs(0 - 3) <= 3
abs(nums[i] - nums[j]) <= valueDiff --> abs(1 - 1) <= 0

Example 2:
Input: nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3
Output: false
Explanation: After trying all the possible pairs (i, j), we cannot satisfy the three
conditions, so we return false.

Constraints:
2 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
1 <= indexDiff <= nums.length
0 <= valueDiff <= 10^9
*****************************************************/

#include "../includes.hpp"

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff,
                                       int valueDiff) {
        // for (size_t left = 0; left < nums.size(); ++left) {
        //     for (size_t right = left + 1; right <= min((left + indexDiff),
        //     nums.size()-1); ++right) {
        //         if ((abs(nums[left] - nums[right]) <= valueDiff)) {
        //             return true;
        //         }
        //     }
        // }
        // return false;
        std::vector<int> minval(nums.size(), INT_MAX);
        std::vector<int> maxval(nums.size(), INT_MIN);

        auto update_minmax = [&](size_t index) -> void {
            minval[index] = INT_MAX;
            maxval[index] = INT_MIN;
            for (size_t k = index; k <= index + indexDiff && k < nums.size(); ++k) {
                minval[index] = std::min(minval[index], nums[k]);
                maxval[index] = std::max(maxval[index], nums[k]);
            }
        };

        update_minmax(0);

        for (size_t i = 1; i < nums.size(); ++i) {
            if (i + indexDiff < nums.size()) {
                minval[i] = std::min(minval[i - 1], nums[i + indexDiff]);
                maxval[i] = std::max(maxval[i - 1], nums[i + indexDiff]);
            } else {
                minval[i] = minval[i - 1];
                maxval[i] = maxval[i - 1];
            }

            if (nums[i - 1] != nums[i + indexDiff]) {
                if (nums[i - 1] == minval[i] || nums[i - 1] == maxval[i]) {
                    update_minmax(i);
                }
            }

            if (maxval[i] - minval[i] <= valueDiff) {
                return true;
            }
        }
        return false;
    }
};

#endif
