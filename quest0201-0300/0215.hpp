#ifndef __0215_H
#define __0215_H

/*****************************************************
Description:
Given an integer array nums and an integer k, return the kth largest element in the
array.

Note that it is the kth largest element in the sorted order, not the kth distinct
element.

You must solve it in O(n) time complexity.

Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

Constraints:
1 <= k <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
*****************************************************/

#include "../includes.hpp"

class Solution {
public:
    int findKthLargest_v0(vector<int> &nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (pq.size() == k) {
                if (pq.top() < nums[i]) {
                    pq.pop();
                    pq.push(nums[i]);
                }
            } else if (pq.size() < k) {
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }

    int findKthLargest_v1(vector<int> &nums, int k) {
        std::vector<int> counter(20001, 0);
        for (size_t i = 0; i < nums.size(); ++i) {
            counter[nums[i] + 10000] += 1;
        }

        for (int idx = 20000, curk = 0; idx >= 0; idx--) {
            curk += counter[idx];
            if (curk >= k) {
                return (idx - 10000);
            }
        }
        return -1;
    }

    int findKthLargest(vector<int> &nums, int k) { return findKthLargest_v1(nums, k); }
};

#endif
