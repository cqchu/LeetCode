#ifndef __0228_H
#define __0228_H

/*****************************************************
Description:
You are given a sorted unique integer array nums.
A range [a,b] is the set of all integers from a to b (inclusive).
Return the smallest sorted list of ranges that cover all the numbers in the array
exactly. That is, each element of nums is covered by exactly one of the ranges, and
there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:
"a->b" if a != b
"a" if a == b

Example 1:
Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"

Example 2:
Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"

Constraints:
0 <= nums.length <= 20
-2^31 <= nums[i] <= 2^31 - 1
All the values of nums are unique.
nums is sorted in ascending order.
*****************************************************/

#include "../includes.hpp"

class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int> &nums) {
        if (nums.size() == 0) {
            return {};
        }

        auto str_range = [](int start, int end) -> std::string {
            if (start != end) {
                return std::to_string(start) + "->" + std::to_string(end);
            } else {
                return std::to_string(start);
            }
        };

        std::vector<std::string> ret;
        int start = nums[0];
        int pre = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            if (pre + 1 != nums[i]) {
                ret.push_back(str_range(start, pre));
                start = nums[i];
            }
            pre = nums[i];
        }
        ret.push_back(str_range(start, pre));
        return ret;
    }
};

#endif
