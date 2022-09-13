#ifndef __0078_H
#define __0078_H

/*******************************************
Description:
Given a set of distinct integers, nums, return all possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.

Example:
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*******************************************/

#include "../includes.hpp"

class Solution {
public:
    void recurse(vector<int>& nums, int curPos, vector<vector<int>>& res) {
        if (curPos == nums.size()-1) {
            vector<int> tmp(0);
            res.push_back(tmp);
            tmp.push_back(nums[curPos]);
            res.push_back(tmp);
        } 
        else {
            recurse(nums, curPos+1, res);
            int len = res.size();
            for (int i=0; i<len; i++) {
                vector<int> tmp(res[i].begin(), res[i].end());
                tmp.push_back(nums[curPos]);
                res.push_back(tmp);
            }
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res(0);
        recurse(nums, 0, res);
        return res;
    }
};
#endif
