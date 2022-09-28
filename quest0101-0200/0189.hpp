#ifndef __0189_H
#define __0189_H

/*****************************************************
Description:
Given an array, rotate the array to the right by k steps, where k is
non-negative.

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

Constraints:
1 <= nums.length <= 10^5
-2^31 <= nums[i] <= 2^31 - 1
0 <= k <= 10^5

Follow up:
Try to come up with as many solutions as you can. There are at least three
different ways to solve this problem. Could you do it in-place with O(1) extra
space?
*****************************************************/

#include "../includes.hpp"

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        if (k == 0 || nums.size() <= 1 || k % nums.size() == 0) {
            return;
        }

        k = k % nums.size();

#if 0
        auto rotate_once = [&]() {
            int last = nums.back();
            for (size_t i=nums.size()-1; i>0; --i) {
                nums[i] = nums[i-1];
            }
            nums[0] = last;
        };

        for (size_t i=0; i<k; ++i) {
            rotate_once();
        }
#elif 0
        std::vector<int> buffer(nums.end() - k, nums.end());
        for (size_t i = nums.size() - 1; i >= k; --i) {
            nums[i] = nums[i - k];
        }
        std::copy(buffer.begin(), buffer.end(), nums.begin());
#else
#if __cplusplus >= 201703L
        size_t iter = std::gcd(nums.size(), k);
#else
        // std::function<size_t(size_t, size_t)> gcd = [&](size_t lhs, size_t
        // rhs) -> size_t {
        //     return rhs != 0 ? gcd(rhs, lhs % rhs) : lhs;
        // };
        auto gcd = [&](size_t lhs, size_t rhs, auto &&self) -> size_t {
            return rhs != 0 ? self(rhs, lhs % rhs, self) : lhs;
        };
        size_t iter = gcd(nums.size(), k, gcd);
#endif
        for (size_t i = 0; i < iter; ++i) {
            size_t cur = i, next = i + k;
            bool started = true;
            int buf = nums[cur];
            while (cur != i || started) {
                started = false;
                std::swap(buf, nums[next]);
                cur = next;
                next += k;
                if (next >= nums.size()) {
                    next -= nums.size();
                }
            }
        }
        LOG_ARRAY(nums);
#endif
    }
};

#endif
