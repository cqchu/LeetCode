#ifndef __0164_H
#define __0164_H

/*****************************************************
Description:
Given an integer array nums, return the maximum difference between two
successive elements in its sorted form. If the array contains less than two
elements, return 0. You must write an algorithm that runs in linear time and
uses linear extra space.

Example 1:
Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9)
has the maximum difference 3.

Example 2:
Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.

Constraints:
1 <= nums.length <= 10^5
0 <= nums[i] <= 10^9
*****************************************************/

#include "../includes.hpp"

class Solution {
public:
    int maximumGap(vector<int> &nums) {
        if (nums.empty() || nums.size() < 2)
            return 0;

        int maxVal = *max_element(nums.begin(), nums.end());
        int exp = 1, radix = 10; // base 10 system

        vector<int> aux(nums.size());

        while (maxVal / exp > 0) { // 一个基数排序
            vector<int> count(radix, 0);
            for (int i = 0; i < nums.size(); i++) // 统计个位为 1, 2, ... 的个数
                count[(nums[i] / exp) % 10]++;

            // partial_sum, 分别表示个位为 1, 个位为 1或 2, 个位为 1或 2或
            // 3的数字个数
            for (int i = 1; i < count.size(); i++)
                count[i] += count[i - 1];

            for (int i = nums.size() - 1; i >= 0; i--) // 根据个位排序
                aux[--count[(nums[i] / exp) % 10]] = nums[i];

            for (int i = 0; i < nums.size(); i++)
                nums[i] = aux[i];

            exp *= 10; // 下一个循环，根据十位排序
        }

        int maxGap = 0;

        for (int i = 0; i < nums.size() - 1; i++)
            maxGap = max(nums[i + 1] - nums[i], maxGap);

        return maxGap;
    }
};

#endif
