#ifndef __0039_H
#define __0039_H

/************************************************
Description:
Given a set of candidate numbers (candidates) (without duplicates) and a target
number (target), find all unique combinations in candidates where the candidate
numbers sums to target. The same repeated number may be chosen from candidates
unlimited number of times.

Note:
    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

Example 2:
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
************************************************/

#include "../includes.hpp"

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> sol;
        // sort()
        for (int i = 0; i < candidates.size(); i++) {
            if (candidates[i] < target) {
                vector<int> tcandidates(candidates.begin() + i, candidates.end());
                vector<vector<int>> tsol =
                    combinationSum(tcandidates, target - candidates[i]);
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
        }
        return sol;
    }
};

#endif
