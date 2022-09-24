#ifndef __0090_H
#define __0090_H

/**********************************************
Description:
Given a collection of integers that might contain duplicates, nums, return all
possible subsets (the power set). Note: The solution set must not contain
duplicate subsets.

Example:
Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
**********************************************/

#include "../includes.hpp"

class Solution {
public:
    void recurse(vector<vector<int>> &res, vector<int> &nums, int curPos,
                 int &updatedLen) {
        if (curPos == nums.size()) {
            res.push_back(vector<int>(0));
            updatedLen = 1;
            return;
        }

        recurse(res, nums, curPos + 1, updatedLen);
        int resLen = res.size();
        if (curPos == nums.size() - 1 || nums[curPos] != nums[curPos + 1])
            updatedLen = resLen;

        for (int i = updatedLen; i > 0; i--) {
            vector<int> tmp(res[resLen - i].begin(), res[resLen - i].end());
            tmp.push_back(nums[curPos]);
            res.push_back(tmp);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int updatedLen = 0;
        recurse(res, nums, 0, updatedLen);
        return res;
    }
};

#endif