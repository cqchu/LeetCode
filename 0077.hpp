#ifndef __0077_H
#define __0077_H

/*******************************************
Description:
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:
Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*******************************************/

#include "includes.hpp"

class Solution {
public:
    void recurse(vector<int>& num, int k, int curPos, vector<vector<int>>& res, vector<int>& visited) {
        if (visited.size() == k) {
            res.push_back(visited);
        }
        else {
            
            for (int i=curPos; i<num.size(); i++) {
                visited.push_back(num[i]);
                recurse(num, k, i+1, res, visited);
                visited.pop_back();
            }
            
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res(0, vector<int>(0));
        vector<int> num(n);
        for (int i=0; i<n; i++) {
            num[i] = i + 1;
        }
        
        vector<int> visited;
        recurse(num, k, 0, res, visited);
        return res;
    }
};

#endif
