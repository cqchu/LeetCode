#ifndef __0046_H
#define __0046_H

/*************************************************
Description:
Given a collection of numbers that might contain duplicates, return all
possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*************************************************/

#include "../includes.hpp"

class Solution {
public:
    void recurse(int curPos, vector<int> nums, vector<vector<int>> &res) {
        if (curPos == nums.size() - 1) {
            res.push_back(nums);
        } else {
            set<int> visit;
            for (int i = curPos; i < nums.size(); i++) {
                if (visit.find(nums[i]) == visit.end()) {
                    visit.insert(nums[i]);
                    swap(nums[curPos], nums[i]);
                    recurse(curPos + 1, nums, res);
                    swap(nums[curPos], nums[i]);
                }
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> res;
        recurse(0, nums, res);
        return res;
    }
};

#endif
