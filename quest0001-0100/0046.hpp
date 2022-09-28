#ifndef __0046_H
#define __0046_H

/*************************************************
Description:
Given a collection of distinct integers, return all possible permutations.

Example:
Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*************************************************/

#include "../includes.hpp"

class Solution {
public:
    vector<vector<int>> recurse(const vector<int> &nums, vector<bool> &visitFlag) {
        vector<vector<int>> res;
        if (nums.size() == 0) {
            vector<int> vi;
            res.push_back(vi);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visitFlag[i] != true) {
                visitFlag[i] = true;
                vector<vector<int>> tres = recurse(nums, visitFlag);
                if (tres.size() == 0) {
                    vector<int> vi;
                    tres.push_back(vi);
                }
                for (int j = 0; j < tres.size(); j++) {
                    tres[j].push_back(nums[i]);
                    res.push_back(tres[j]);
                }
                visitFlag[i] = false;
            }
        }
        return res;
    }
    vector<vector<int>> permute(vector<int> &nums) {
        vector<bool> visitFlag(nums.size(), false);
        vector<vector<int>> res = recurse(nums, visitFlag);
        return res;
    }
};

#endif
