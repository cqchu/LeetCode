#ifndef __0040_H
#define __0040_H

/************************************************
Description:
Given a collection of candidate numbers (candidates) and a target number
(target), find all unique combinations in candidates where the candidate
numbers sums to target. Each number in candidates may only be used once in the
combination.

Note:
    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
************************************************/

#include "../includes.hpp"

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int>> sol;
        sort(candidates.begin(), candidates.end());
        for (int i = 0; i < candidates.size(); i++) {
            if (candidates[i] < target) {
                vector<int> tcandidates(candidates.begin() + i + 1,
                                        candidates.end());
                vector<vector<int>> tsol =
                    combinationSum2(tcandidates, target - candidates[i]);
                if (tsol.size() != 0) {
                    for (auto ts : tsol) {
                        ts.push_back(candidates[i]);
                        sol.push_back(ts);
                    }
                }
            }
            if (candidates[i] == target) {
                vector<int> vi = {target};
                sol.push_back(vi);
            }
            while (i + 1 < candidates.size() &&
                   candidates[i + 1] == candidates[i]) {
                i++;
            }
        }
        return sol;
    }
};

#endif
