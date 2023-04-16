#ifndef __0219_H
#define __0219_H

/*****************************************************
Description:
Given an integer array nums and an integer k, return true if there are two distinct
indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

Example 1:
Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:
Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:
Input: nums = [1,2,3,1,2,3], k = 2
Output: false

Constraints:
1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
0 <= k <= 10^5
*****************************************************/

#include "../includes.hpp"

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        if (nums.size() < 2 || k == 0) {
            return false;
        }

        std::queue<int> q;
        std::unordered_set<int> s;

        for (size_t i = 0; i < nums.size(); ++i) {
            if (s.find(nums[i]) != s.end()) {
                return true;
            }
            if (q.size() >= k) {
                int head = q.front();
                q.pop();
                s.erase(head);
            }
            q.push(nums[i]);
            s.emplace(nums[i]);
        }
        return false;
    }
};

#endif
